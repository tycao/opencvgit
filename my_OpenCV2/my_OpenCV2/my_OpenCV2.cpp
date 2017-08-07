// my_OpenCV2.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include "stdafx.h"
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	//-----------------------------------【一、图像的载入和显示】--------------------------------------  
	//     描述：以下三行代码用于完成图像的载入和显示  
	//--------------------------------------------------------------------------------------------------  

	Mat girl = imread("C:\\Users\\Administrator\\Desktop\\my_OpenCV2\\m1.png"); //载入图像到Mat  
	namedWindow("【1】动漫图"); //创建一个名为 "【1】动漫图"的窗口   
	imshow("【1】动漫图", girl);//显示名为 "【1】动漫图"的窗口   

	//载入图片  
	Mat image = imread("C:\\Users\\Administrator\\Desktop\\my_OpenCV2\\m2.png", 199);
	Mat logo = imread("C:\\Users\\Administrator\\Desktop\\my_OpenCV2\\m3.png");

	//载入后先显示  
	namedWindow("【2】原画图");
	imshow("【2】原画图", image);

	namedWindow("【3】logo图");
	imshow("【3】logo图", logo);

	//定义一个Mat类型，用于存放，图像的ROI  
	//Mat imageROI;
	//方法一  
	//imageROI = image(Rect(10, 10, logo.cols, logo.rows));
	//imageROI =  image(Rect(800, 350, logo.cols, logo.rows));
	Mat imageROI(image, Rect(800, 350, logo.cols, logo.rows));
	//方法二  
	//imageROI=image(Range(350,350+logo.rows),Range(800,800+logo.cols));  

	//将logo加到原图上  
	addWeighted(imageROI, 0.5, logo, 0.3, 0., imageROI);

	//显示结果  
	namedWindow("【4】原画+logo图");
	imshow("【4】原画+logo图", image);
	
	//-----------------------------------【三、图像的输出】--------------------------------------  
	//     描述：将一个Mat图像输出到图像文件  
	//-----------------------------------------------------------------------------------------------  
	//输出一张jpg图片到工程目录下  
	imwrite("我喜欢打dota2 by浅墨.jpg", image);
	imwrite("我喜欢打王者荣耀 by曹四喜.png", logo);
	imwrite("我喜欢打王者荣耀 by四喜.bmp", girl);

	waitKey();
	return 0;
}

