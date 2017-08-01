#include<opencv2\opencv.hpp>  
#include<opencv2\imgproc\imgproc.hpp>  
#include<opencv2\imgproc\imgproc_c.h>  
#include<opencv2\highgui\highgui.hpp>  

int main()
{
	//【1】加载原图  
	IplImage* srcImg = cvLoadImage("e:\\IMG_2576.JPG");
	cvNamedWindow("【srcImg】");
	cvShowImage("【srcImg】", srcImg);

	CvSize grayImgSize;
	grayImgSize.height = srcImg->height;
	grayImgSize.width = srcImg->width;
	//【2】转换为灰度图  
	IplImage* grayImg = cvCreateImage(grayImgSize, srcImg->depth, 1);
	cvCvtColor(srcImg, grayImg, CV_BGR2GRAY);
	cvNamedWindow("【grayImg】");
	cvShowImage("【grayImg】", grayImg);
	//【3】转换为二值图  
	IplImage* binaryImg = cvCreateImage(grayImgSize, grayImg->depth, 1);
	cvThreshold(grayImg, binaryImg, 145, 255, CV_THRESH_BINARY);
	cvNamedWindow("【binaryImg】");
	cvShowImage("【binaryImg】", binaryImg);


	cvSaveImage("C:\\Users\\Administrator\\Desktop\\binaryImg.jpg", binaryImg);  //保存二值图  
	cvSaveImage("C:\\Users\\Administrator\\Desktop\\grayImg.png", grayImg);	// 保存灰度图
	cv::waitKey(0);
	//【4】释放内存空间  
	cvDestroyWindow("【srcImg】");
	cvDestroyWindow("【grayImg】");
	cvDestroyWindow("【binaryImg】");
	cvReleaseImage(&srcImg);
	cvReleaseImage(&grayImg);
	cvReleaseImage(&binaryImg);
	return 0;
}