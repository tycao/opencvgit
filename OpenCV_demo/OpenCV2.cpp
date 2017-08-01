#include "opencv2/opencv.hpp"
using namespace std;
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")  
int main()
{
	const char *pstrImageName = "C:\\Users\\Administrator\\Desktop\\aa.jpg";
	const char *pstrWindowsTitle = "³ÌÐò";
	IplImage *pImage = cvLoadImage(pstrImageName, 1);
	cvNamedWindow(pstrWindowsTitle, CV_WINDOW_AUTOSIZE);
	cvShowImage(pstrWindowsTitle, pImage);
	cvWaitKey(0);
	cvDestroyWindow(pstrWindowsTitle);
	cvReleaseImage(&pImage);
	return 0;
}