#include<opencv2\opencv.hpp>  
#include<opencv2\imgproc\imgproc.hpp>  
#include<opencv2\imgproc\imgproc_c.h>  
#include<opencv2\highgui\highgui.hpp>  
/*
int main()
{
	
	//【1】加载原图  
	IplImage* srcImg = cvLoadImage("C:\\Users\\Administrator\\Desktop\\aa.jpg");
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
*/

/**********************************************************************************************************
*文件说明:
*        基于OpenCv的阈值分割算法
*开发环境:
*        win7+vs2013+opencv2.4.9
*时间地点:
*        安徽科技学院.2017.2.24
*作    者:
*        曹四喜
***********************************************************************************************************/
#include<stdio.h>  
#include<cv.h>  
#include<highgui.h>  

void sum_rgb(IplImage*src, IplImage*dst)
{
	IplImage* r = cvCreateImage(cvGetSize(src), src->depth, 1);
	IplImage* g = cvCreateImage(cvGetSize(src), src->depth, 1);
	IplImage* b = cvCreateImage(cvGetSize(src), src->depth, 1);

	cvSplit(src, r, g, b, NULL);                    // cvSplit是具有分别复制每个通道到多单通道图像功能的openCV中的一个函数。  

	IplImage* s = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);

	cvAddWeighted(r, 1. / 3., g, 1. / 3., 0.0, s);
	cvAddWeighted(s, 2. / 3., b, 1. / 3., 0.0, s);

	cvThreshold(s, dst, 100, 100, CV_THRESH_TRUNC); //进行阈值化处理  

	cvReleaseImage(&r);
	cvReleaseImage(&g);
	cvReleaseImage(&b);
	cvReleaseImage(&s);

}
//主函数入口  
int main(int argc, char** argv)
{
	IplImage* src = cvLoadImage("C:\\Users\\Administrator\\Desktop\\aa.jpg"); //cvNamedWindow("【1】",1);  cvShowImage("【1】",src);  
	cvNamedWindow("原图", 1);
	cvShowImage("原图", src);
	IplImage* dst = cvCreateImage(cvGetSize(src), src->depth, 1);
	sum_rgb(src, dst);

	cvNamedWindow("C:\\Users\\Administrator\\Desktop\\aa.jpg", 1);
	cvShowImage("C:\\Users\\Administrator\\Desktop\\\\aa.jpg", dst);
	while (1)
	{
		if ((cvWaitKey(10) & 0x7f) == 27)break;
	}
	cvDestroyWindow("C:\\Users\\Administrator\\Desktop\\\\aa.jpg");
	cvReleaseImage(&src);
	cvReleaseImage(&dst);
}