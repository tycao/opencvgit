// resize.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <iostream> 

using namespace std;
using namespace cv;


int main(int argc, _TCHAR* argv[])
{
	const char *pstrImageName = "C:\\Users\\Administrator\\Desktop\\aa.jpg";
	const char *pstrWindowsTitle = "My OpenCV";
	IplImage *pImage = cvLoadImage(pstrImageName, 1);
	cvNamedWindow(pstrWindowsTitle, CV_WINDOW_AUTOSIZE);
	cvShowImage(pstrWindowsTitle, pImage);
	cvWaitKey(0);
	cvDestroyWindow(pstrWindowsTitle);
	cvReleaseImage(&pImage);


	return 0;
}

