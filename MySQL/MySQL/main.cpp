#include <iostream>
#include <winsock2.h>
#include <string>
#include <ctime>

#include "mysql.h"

#pragma comment(lib, "C:\\wamp64\\bin\\mysql\\mysql5.7.19\\lib\\libmysql.lib")

using namespace std;

int main()
{
	MYSQL mysql;
	mysql_init(&mysql); // ��ʼ��

	MYSQL *ConnStatus = mysql_real_connect(&mysql, "localhost", "root", "", "sky", 3306, 0, 0);
	if (ConnStatus == nullptr)
	{
		// ����ʧ��
		int i = mysql_errno(&mysql);
		string strError = mysql_error(&mysql);
		cout << "Error info: " << strError << endl;

		return 0;
	}

	cout << "Mysql Connected..." << endl;

	string strsql;
	MYSQL_RES *result = nullptr; // ���ݽ����

	// �������
	strsql = "insert into t1 set name = 'sky'";

	clock_t t1 = clock();

	mysql_query(&mysql, "START TRANSACTION"); // �������� ���û�п���������ôЧ�ʻ��÷ǳ����£�

	for (int i = 0; i<10000; i++)
	{
		mysql_query(&mysql, strsql.c_str());
	}

	mysql_query(&mysql, "COMMIT");   // �ύ����
	//mysql_commit(&mysql);
	clock_t t2 = clock();
	cout << "insert end\n" 
		<< "Cost time : " << (t2 - t1) / 1000.
		<< endl;

	//�ͷŽ���� �ر����ݿ�
	mysql_free_result(result);
	mysql_close(&mysql);
	mysql_library_end();

	return 0;
}