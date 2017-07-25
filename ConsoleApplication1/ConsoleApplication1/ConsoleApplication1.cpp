// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h" 
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

int main(int argc, char* argv[])

{
	//从文件中读入图像
	Mat img = imread("C:\\Users\\Administrator\\Desktop\\1.jpg");
	//如果读入图像失败
	if (!img.data)
	{
		cout << "Can not load the image!" << endl;
		return -1;
	}
	//显示图像
	namedWindow("C:\\Users\\Administrator\\Desktop\\1.jpg");
	imshow("C:\\Users\\Administrator\\Desktop\\1.jpg", img);
	//此函数等待按键，按键盘任意键就返回
	waitKey();
	return 0;
}
