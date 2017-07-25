// video_opencv2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <iostream>  

#pragma comment( lib, "opencv_core249.lib" )  
#pragma comment( lib, "opencv_highgui249.lib" )  
#pragma comment( lib, "opencv_imgproc249.lib" )  

using namespace cv;
using namespace std;

int main(int argc, const char **argv)
{

	VideoCapture cap(0); // open the default camera  
	if (!cap.isOpened()) // check if we succeeded  
		return -1;
	Mat edges;
	namedWindow("edges", 1);
	for (;;)
	{
		Mat frame;
		cap >> frame; // get a new frame from camera  
		cvtColor(frame, edges, CV_BGR2GRAY);
		GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);
		Canny(edges, edges, 0, 30, 3);
		imshow("edges", edges);
		if (waitKey(30) >= 0) break;
	}
	// the camera will be deinitialized automatically in VideoCapture destructor  
	return 0;
}