//
// handler.hpp
// web_server
// created by changkun at shiyanlou.com
//

#include "server_base.h"
#include <fstream>

using namespace std;
using namespace ShiyanlouWeb;

template<typename SERVER_TYPE>
void start_server(SERVER_TYPE &server)
{
    // �����������������Դ�Ĵ�����

    // ������� /string �� POST ���󣬷��� POST ���ַ���
    server.resource["^/string/?$"]["POST"] = [](ostream& response, Request& request) {
        // �� istream �л�ȡ�ַ��� (*request.content)
        stringstream ss;
        *request.content >> ss.rdbuf();     // ���������ݶ�ȡ�� stringstream
        string content=ss.str();

        // ֱ�ӷ���������
        response << "HTTP/1.1 200 OK\r\nContent-Length: " << content.length() << "\r\n\r\n" << content;
    };

    // ������� /info �� GET ����, �����������Ϣ
    server.resource["^/info/?$"]["GET"] = [](ostream& response, Request& request) {
        stringstream content_stream;
        content_stream << "<h1>Request:</h1>";
        content_stream << request.method << " " << request.path << " HTTP/" << request.http_version << "<br>";
        for(auto& header: request.header) {
            content_stream << header.first << ": " << header.second << "<br>";
        }

        // ��� content_stream �ĳ���(ʹ�� content.tellp() ���)
        content_stream.seekp(0, ios::end);

        response <<  "HTTP/1.1 200 OK\r\nContent-Length: " << content_stream.tellp() << "\r\n\r\n" << content_stream.rdbuf();
    };

    // ������� /match/[��ĸ+������ɵ��ַ���] �� GET ����, ����ִ������ GET /match/abc123, ������ abc123
    server.resource["^/match/([0-9a-zA-Z]+)/?$"]["GET"] = [](ostream& response, Request& request) {
        string number=request.path_match[1];
        response << "HTTP/1.1 200 OK\r\nContent-Length: " << number.length() << "\r\n\r\n" << number;
    };

    // ����Ĭ�� GET ����, ���û������ƥ��ɹ�����������������ᱻ����
    // ��Ӧ�� web/ Ŀ¼������Ŀ¼�е��ļ�
    // Ĭ���ļ�: index.html
    server.default_resource["^/?(.*)$"]["GET"] = [](ostream& response, Request& request) {
        string filename = "C:/Users/Administrator/Documents/Visual Studio 2013/Projects/Cpp_STL/STL_Algorithm/Cpp_Web/www/";

        string path = request.path_match[1];

        // ��ֹʹ�� `..` ������ web/ Ŀ¼�������
        size_t last_pos = path.rfind(".");
        size_t current_pos = 0;
        size_t pos;
        while((pos = path.find('.', current_pos)) != string::npos && pos != last_pos) {
            current_pos = pos;
            path.erase(pos, 1);
            --last_pos;
        }

        filename += path;
        ifstream ifs;
        // �򵥵�ƽ̨�޹ص��ļ���Ŀ¼���
        if(filename.find('.') == string::npos) {
            if(filename[filename.length()-1]!='/')
                filename+='/';
            filename += "index.html";
        }
        ifs.open(filename, ifstream::in);

        if(ifs) {
            ifs.seekg(0, ios::end);
            size_t length=ifs.tellg();

            ifs.seekg(0, ios::beg);

            // �ļ����ݿ����� response-stream �У���Ӧ�����ڴ����ļ�
            response << "HTTP/1.1 200 OK\r\nContent-Length: " << length << "\r\n\r\n" << ifs.rdbuf();

            ifs.close();
        } else {
            // �ļ�������ʱ�������޷����ļ�
            string content="Could not open file "+filename;
            response << "HTTP/1.1 400 Bad Request\r\nContent-Length: " << content.length() << "\r\n\r\n" << content;
        }
    };

    // ���� HTTP ������
    server.start();
}
