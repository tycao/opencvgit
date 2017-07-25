// video_opencv.cpp : 定义控制台应用程序的入口点。
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
		imshow("camera", img_src);//可以事先不用新建一个窗口  
		char c = (char)waitKey(30);
		if (c == 27)
		{
			break;
		}
	}
	return 0;
}