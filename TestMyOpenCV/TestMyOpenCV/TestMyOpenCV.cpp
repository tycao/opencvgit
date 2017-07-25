// TestMyOpenCV.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>  
#include <opencv2/highgui/highgui.hpp>  

using namespace cv;
using namespace std;

int main(int argc, _TCHAR* argv[])
{
	/*
		Mat image = imread("C:\\Users\\Administrator\\Documents\\Visual Studio 2013\\Projects\\TestMyOpenCV\\x64\\Debug\\a.jpg");
		if (image.empty())
		{
		cout << "Can not load the image!" << endl;
		return -1;
		}

		namedWindow("C:\\Users\\Administrator\\Desktop\\aa.jpg");
		imshow("My OpenCV", image);
		waitKey(6000);
		return 0;
		}
*/

		const char *pstrImageName = "C:\\Users\\Administrator\\Desktop\\aa.jpg";
		const char *pstrWindowsTitle = "我的第一个OpenCV程序";
		IplImage *pImage = cvLoadImage(pstrImageName, 1);
		cvNamedWindow(pstrWindowsTitle, CV_WINDOW_AUTOSIZE);
		cvShowImage(pstrWindowsTitle, pImage);
		cvWaitKey(0);
		cvDestroyWindow(pstrWindowsTitle);
		cvReleaseImage(&pImage);

		return 0;
}
