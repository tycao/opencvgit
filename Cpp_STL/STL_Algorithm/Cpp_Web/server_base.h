//
// server_base.hpp
// web_server
// created by changkun at shiyanlou.com
//

#pragma once

#include <boost/asio.hpp>

#include <regex>
#include <unordered_map>
#include <thread>

namespace ShiyanlouWeb {
    struct Request {
        // ���󷽷�, POST, GET; ����·��; HTTP �汾
        std::string method, path, http_version;
        // �� content ʹ������ָ��������ü���
        std::shared_ptr<std::istream> content;
        // ��ϣ����, key-value �ֵ�
        std::unordered_map<std::string, std::string> header;
        // ��������ʽ����·��ƥ��
        std::smatch path_match;
    };

    // ʹ�� typedef ����Դ���͵ı�ʾ��ʽ
    typedef std::map<std::string, std::unordered_map<std::string,
    std::function<void(std::ostream&, Request&)>>> resource_type;

    // socket_type Ϊ HTTP or HTTPS
    template <typename socket_type>
    class ServerBase {
    public:
        resource_type resource;
        resource_type default_resource;

        // ���������, ��ʼ���˿�, Ĭ��ʹ��һ���߳�
        ServerBase(unsigned short port, size_t num_threads = 1) :
            endpoint(boost::asio::ip::tcp::v4(), port),
            acceptor(m_io_service, endpoint),
            num_threads(num_threads) {}

        void start() {
            // Ĭ����Դ���� vector ��ĩβ, ����Ӧ�𷽷�
            for(auto it = resource.begin(); it != resource.end(); it++) {
                all_resources.push_back(it);
            }
            for(auto it = default_resource.begin(); it != default_resource.end(); it++) {
                all_resources.push_back(it);
            }

            // ���� socket �����ӷ�ʽ
            accept();

            // ��� num_threads>1, ��ô m_io_service.run()
            // ������ (num_threads-1) �̳߳�Ϊ�̳߳�
            for(size_t c = 1;c < num_threads; c++) {
                threads.emplace_back([this](){
                    m_io_service.run();
                });
            }

            // ���߳�
            m_io_service.run();

            // �ȴ������̣߳�����еĻ�, �͵ȴ���Щ�̵߳Ľ���
            for(auto& t: threads)
                t.join();
        }
    protected:
        // asio ���е� io_service �ǵ����������е��첽 IO �¼���Ҫͨ�������ַ�����
        // ���仰˵, ��Ҫ IO �Ķ���Ĺ��캯��������Ҫ����һ�� io_service ����
        boost::asio::io_service m_io_service;
        // IP ��ַ���˿ںš�Э��汾����һ�� endpoint����ͨ����� endpoint �ڷ��������
        // tcp::acceptor ���󣬲���ָ���˿��ϵȴ�����
        boost::asio::ip::tcp::endpoint endpoint;
        // ���ԣ�һ�� acceptor ����Ĺ��춼��Ҫ io_service �� endpoint ��������
        boost::asio::ip::tcp::acceptor acceptor;

        // �������߳�
        size_t num_threads;
        std::vector<std::thread> threads;

        // ���е���Դ��Ĭ����Դ������ vector β�����, ���� start() �д���
        std::vector<resource_type::iterator> all_resources;

        // ��Ҫ��ͬ���͵ķ�����ʵ���������
        virtual void accept() {}

        // ���������Ӧ��
        void process_request_and_respond(std::shared_ptr<socket_type> socket) const {
            // Ϊ async_read_untile() �����µĶ�����
            // Shared_ptr ���ڴ�����ʱ�������������
            // �ᱻ�Ƶ�Ϊ std::shared_ptr<boost::asio::streambuf>
            auto read_buffer = std::make_shared<boost::asio::streambuf>();

            boost::asio::async_read_until(*socket, *read_buffer, "\r\n\r\n",
            [this, socket, read_buffer](const boost::system::error_code& ec, size_t bytes_transferred) {
                if(!ec) {
                    // ע�⣺read_buffer->size() �Ĵ�С��һ���� bytes_transferred ��ȣ� Boost ���ĵ���ָ����
                    // �� async_read_until �����ɹ���,  streambuf �ڽ綨��֮����ܰ���һЩ����ĵ�����
                    // ���ԽϺõ�������ֱ�Ӵ�������ȡ��������ǰ read_buffer ��ߵı�ͷ, ��ƴ�� async_read ���������
                    size_t total = read_buffer->size();

                    // ת���� istream ����ȡ string-lines
                    std::istream stream(read_buffer.get());

                    // ���Ƶ�Ϊ std::shared_ptr<Request> ����
                    auto request = std::make_shared<Request>();
                    *request = parse_request(stream);

                    size_t num_additional_bytes = total - bytes_transferred;

                    // ������㣬ͬ����ȡ
                    if(request->header.count("Content-Length") > 0) {
                        boost::asio::async_read(*socket, *read_buffer,
                        boost::asio::transfer_exactly(stoull(request->header["Content-Length"]) - num_additional_bytes),
                        [this, socket, read_buffer, request](const boost::system::error_code& ec, size_t bytes_transferred) {
                            if(!ec) {
                                // ��ָ����Ϊ istream ����洢�� read_buffer ��
                                request->content = std::shared_ptr<std::istream>(new std::istream(read_buffer.get()));
                                respond(socket, request);
                            }
                        });
                    } else {
                        respond(socket, request);
                    }
                }
            });
        }

        // ��������
        Request parse_request(std::istream& stream) const {
            Request request;

            std::regex e("^([^ ]*) ([^ ]*) HTTP/([^ ]*)$");

            std::smatch sub_match;

            //�ӵ�һ���н������󷽷���·���� HTTP �汾
            std::string line;
            getline(stream, line);
            line.pop_back();
            if(std::regex_match(line, sub_match, e)) {
                request.method       = sub_match[1];
                request.path         = sub_match[2];
                request.http_version = sub_match[3];

                bool matched;
                e="^([^:]*): ?(.*)$";
                // ����ͷ����������Ϣ
                do {
                    getline(stream, line);
                    line.pop_back();
                    matched=std::regex_match(line, sub_match, e);
                    if(matched) {
                        request.header[sub_match[1]] = sub_match[2];
                    }

                } while(matched==true);
            }
            return request;
        }

        // Ӧ��
        void respond(std::shared_ptr<socket_type> socket, std::shared_ptr<Request> request) const
        {
            // ������·���ͷ�������ƥ����ң���������Ӧ
            for(auto res_it: all_resources) {
                std::regex e(res_it->first);
                std::smatch sm_res;
                if(std::regex_match(request->path, sm_res, e)) {
                    if(res_it->second.count(request->method)>0) {
                        request->path_match = move(sm_res);

                        // �ᱻ�Ƶ�Ϊ std::shared_ptr<boost::asio::streambuf>
                        auto write_buffer = std::make_shared<boost::asio::streambuf>();
                        std::ostream response(write_buffer.get());
                        res_it->second[request->method](response, *request);

                        // �� lambda �в��� write_buffer ʹ�䲻���� async_write ���ǰ������
                        boost::asio::async_write(*socket, *write_buffer,
                        [this, socket, request, write_buffer](const boost::system::error_code& ec, size_t bytes_transferred) {
                            //HTTP �־�����(HTTP 1.1):
                            if(!ec && stof(request->http_version)>1.05)
                                process_request_and_respond(socket);
                        });
                        return;
                    }
                }
            }
        }

    };

    template<typename socket_type>
    class Server : public ServerBase<socket_type> {};
}
