// video_opencv.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"  
#include <opencv2/highgui/highgui.hpp>  

using namespace cv;

int main(int argc, unsigned char* argv[])
{
	Mat img_src;
	VideoCapture cam(0);
	for (;;)
	{
		cam >> img_src;
		imshow("camera", img_src);//�������Ȳ����½�һ������  
		char c = (char)waitKey(30);
		if (c == 27)
		{
			break;
		}
	}
	return 0;
}