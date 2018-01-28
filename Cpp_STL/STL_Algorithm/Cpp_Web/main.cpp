//
// main_http.cpp
// web_server
// created by changkun at shiyanlou.com
//


#include "server_http.h"
#include "handler.h"

using namespace ShiyanlouWeb;

int main() {
    // HTTP ���������� 12345 �˿ڣ��������ĸ��߳�
    Server<HTTP> server(12345, 4);
    start_server<Server<HTTP>>(server);
    return 0;
}
