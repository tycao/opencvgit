// my_OpenCV2.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//-----------------------------------��һ��ͼ����������ʾ��--------------------------------------  
	//     �������������д����������ͼ����������ʾ  
	//--------------------------------------------------------------------------------------------------  

	Mat girl = imread("C:\\Users\\Administrator\\Desktop\\my_OpenCV2\\m1.png"); //����ͼ��Mat  
	namedWindow("��1������ͼ"); //����һ����Ϊ "��1������ͼ"�Ĵ���   
	imshow("��1������ͼ", girl);//��ʾ��Ϊ "��1������ͼ"�Ĵ���   

	//����ͼƬ  
	Mat image = imread("C:\\Users\\Administrator\\Desktop\\my_OpenCV2\\m2.png", 199);
	Mat logo = imread("C:\\Users\\Administrator\\Desktop\\my_OpenCV2\\m3.png");

	//���������ʾ  
	namedWindow("��2��ԭ��ͼ");
	imshow("��2��ԭ��ͼ", image);

	namedWindow("��3��logoͼ");
	imshow("��3��logoͼ", logo);

	//����һ��Mat���ͣ����ڴ�ţ�ͼ���ROI  
	//Mat imageROI;
	//����һ  
	//imageROI = image(Rect(10, 10, logo.cols, logo.rows));
	//imageROI =  image(Rect(800, 350, logo.cols, logo.rows));
	Mat imageROI(image, Rect(800, 350, logo.cols, logo.rows));
	//������  
	//imageROI=image(Range(350,350+logo.rows),Range(800,800+logo.cols));  

	//��logo�ӵ�ԭͼ��  
	addWeighted(imageROI, 0.5, logo, 0.3, 0., imageROI);

	//��ʾ���  
	namedWindow("��4��ԭ��+logoͼ");
	imshow("��4��ԭ��+logoͼ", image);
	
	//-----------------------------------������ͼ��������--------------------------------------  
	//     ��������һ��Matͼ�������ͼ���ļ�  
	//-----------------------------------------------------------------------------------------------  
	//���һ��jpgͼƬ������Ŀ¼��  
	imwrite("��ϲ����dota2 byǳī.jpg", image);
	imwrite("��ϲ����������ҫ by����ϲ.png", logo);
	imwrite("��ϲ����������ҫ by��ϲ.bmp", girl);

	waitKey();
	return 0;
}

