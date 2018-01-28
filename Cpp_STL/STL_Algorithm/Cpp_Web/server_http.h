//
// server_http.hpp
// web_server
// created by changkun at shiyanlou.com
//

#ifndef SERVER_HTTP_HPP
#define	SERVER_HTTP_HPP

#include "server_base.h"

namespace ShiyanlouWeb {
    typedef boost::asio::ip::tcp::socket HTTP;
    template<>
    class Server<HTTP> : public ServerBase<HTTP> {
    public:
        // ͨ���˿ںš��߳��������� Web ������, HTTP �������Ƚϼ򵥣�����Ҫ����������ļ��ĳ�ʼ��
        Server(unsigned short port, size_t num_threads=1) :
            ServerBase<HTTP>::ServerBase(port, num_threads) {}
    private:
        // ʵ�� accept() ����
        void accept() {
            // Ϊ��ǰ���Ӵ���һ���µ� socket
            // Shared_ptr ���ڴ�����ʱ�������������
            // socket �ᱻ�Ƶ�Ϊ std::shared_ptr<HTTP> ����
            auto socket = std::make_shared<HTTP>(m_io_service);

            acceptor.async_accept(*socket, [this, socket](const boost::system::error_code& ec) {
                // ��������������һ������
                accept();
                // ������ִ���
                if(!ec) process_request_and_respond(socket);
            });
        }
    };
}
#endif	/* SERVER_HTTP_HPP */
