// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h" 
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

int main(int argc, char* argv[])

{
	//���ļ��ж���ͼ��
	Mat img = imread("C:\\Users\\Administrator\\Desktop\\1.jpg");
	//�������ͼ��ʧ��
	if (!img.data)
	{
		cout << "Can not load the image!" << endl;
		return -1;
	}
	//��ʾͼ��
	namedWindow("C:\\Users\\Administrator\\Desktop\\1.jpg");
	imshow("C:\\Users\\Administrator\\Desktop\\1.jpg", img);
	//�˺����ȴ�������������������ͷ���
	waitKey();
	return 0;
}
