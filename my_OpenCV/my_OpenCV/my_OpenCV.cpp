// my_OpenCV.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <vector>
#include <iostream>
#include <opencv2/core/core.hpp>  
#include<opencv2/highgui/highgui.hpp>  
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/*
int main(int argc, const char** argv)
{	
	
	Mat ima = imread("C:\\Users\\Administrator\\Desktop\\aa.jpg"); //载入图像到Mat  
	Mat logo = imread("C:\\Users\\Administrator\\Desktop\\a3.jpg");

	if (ima.empty())	// 判断图片是否读取成功
	{
		cout << "ooooops....failed to open image...." << endl;
		return -1;
	}
	namedWindow("【1】动漫图"); //创建一个名为 "【1】动漫图"的窗口   
	imshow("【1】动漫图", ima);//显示名为 "【1】动漫图"的窗口   

	namedWindow("【3】logo图");
	imshow("【3】logo图", logo);

	imwrite("C:\\Users\\Administrator\\Desktop\\Beauty2.png", logo);
	

	/////////////////////////////////////////////////////////////////////////////
	double alpha = 0.5; double beta; double input;

	Mat src1, src2, dst;

	/// Ask the user enter alpha
	std::cout << " Simple Linear Blender " << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "* Enter alpha [0-1]: ";
	std::cin >> input;

	// We use the alpha provided by the user iff it is between 0 and 1
	if (alpha >= 0 && alpha <= 1)
	{
		alpha = input;
	}

	/// Read image ( same size, same type )
	src1 = imread("C:\\Users\\Administrator\\Desktop\\Beauty2.png");
	src2 = imread("C:\\Users\\Administrator\\Desktop\\Beauty.png");

	if (!src1.data) { printf("Error loading src1 \n"); return -1; }
	if (!src2.data) { printf("Error loading src2 \n"); return -1; }

	/// Create Windows
	namedWindow("Linear Blend", 1);

	beta = (1.0 - alpha);
	addWeighted(src1, alpha, src2, beta, 0.0, dst);

	imshow("Linear Blend", dst);


	waitKey(0);
	return 0;

	waitKey();
	
	return 0;
}

*/

/// Modifies an already allocated image header to map
/// a subwindow inside another image.
inline void subImage(IplImage *dest, const IplImage *orig, const CvRect &r)
{
	dest->width = r.width;
	dest->height = r.height;
	dest->imageSize = r.height * orig->widthStep;
	dest->imageData = orig->imageData + r.y * orig->widthStep + r.x * orig->nChannels;
	dest->widthStep = orig->widthStep;
	dest->roi = NULL;
	dest->nSize = sizeof(IplImage);
	dest->depth = orig->depth;
	dest->nChannels = orig->nChannels;
	dest->dataOrder = IPL_DATA_ORDER_PIXEL;
}

int _tmain(int argc, _TCHAR* argv[])
{
	IplImage targetImage;
	IplImage* showImg = cvLoadImage("C:\\Users\\Administrator\\Desktop\\aa.jpg");
	cvNamedWindow("Fuck");
	cvShowImage("Fuck", showImg);

	//printf("\ntargetImage->width =%d, targetImage->height =%d ", targetImage->width, targetImage->height );

	//IplImage* cap = cvCreateImage(cvSize(targetImage->width, targetImage->height), IPL_DEPTH_8U, 1);
	//cvCvtColor(targetImage, cap, CV_BGR2GRAY);//HERE NO PROBLEM

	CvRect xargetRect = cvRect(500, 500, 800, 800);
	subImage(&targetImage, showImg, xargetRect);
	IplImage* cap = cvCreateImage(cvSize(targetImage.width, targetImage.height), IPL_DEPTH_8U, 1);
	printf("\ntargetImage->width =%d, targetImage->height =%d ", targetImage.width, targetImage.height);
	printf("\ncap->width =%d, cap->height =%d ", cap->width, cap->height);
	cvCvtColor(&targetImage, cap, CV_BGR2GRAY); //HERE THE PROBLEM

	int result = cvSaveImage("C:\\Users\\Administrator\\Desktop\\Fuck_Beauty.png", &targetImage);
	cout << result << endl;

	waitKey();
	return 0;
}