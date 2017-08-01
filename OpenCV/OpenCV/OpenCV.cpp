#include<opencv2\opencv.hpp>  
#include<opencv2\imgproc\imgproc.hpp>  
#include<opencv2\imgproc\imgproc_c.h>  
#include<opencv2\highgui\highgui.hpp>  
/*
int main()
{
	
	//��1������ԭͼ  
	IplImage* srcImg = cvLoadImage("C:\\Users\\Administrator\\Desktop\\aa.jpg");
	cvNamedWindow("��srcImg��");
	cvShowImage("��srcImg��", srcImg);

	CvSize grayImgSize;
	grayImgSize.height = srcImg->height;
	grayImgSize.width = srcImg->width;
	//��2��ת��Ϊ�Ҷ�ͼ  
	IplImage* grayImg = cvCreateImage(grayImgSize, srcImg->depth, 1);
	cvCvtColor(srcImg, grayImg, CV_BGR2GRAY);
	cvNamedWindow("��grayImg��");
	cvShowImage("��grayImg��", grayImg);
	//��3��ת��Ϊ��ֵͼ  
	IplImage* binaryImg = cvCreateImage(grayImgSize, grayImg->depth, 1);
	cvThreshold(grayImg, binaryImg, 145, 255, CV_THRESH_BINARY);
	cvNamedWindow("��binaryImg��");
	cvShowImage("��binaryImg��", binaryImg);


	cvSaveImage("C:\\Users\\Administrator\\Desktop\\binaryImg.jpg", binaryImg);  //�����ֵͼ  
	cvSaveImage("C:\\Users\\Administrator\\Desktop\\grayImg.png", grayImg);	// ����Ҷ�ͼ
	cv::waitKey(0);
	//��4���ͷ��ڴ�ռ�  
	cvDestroyWindow("��srcImg��");
	cvDestroyWindow("��grayImg��");
	cvDestroyWindow("��binaryImg��");
	cvReleaseImage(&srcImg);
	cvReleaseImage(&grayImg);
	cvReleaseImage(&binaryImg);


	return 0;
}
*/

/**********************************************************************************************************
*�ļ�˵��:
*        ����OpenCv����ֵ�ָ��㷨
*��������:
*        win7+vs2013+opencv2.4.9
*ʱ��ص�:
*        ���տƼ�ѧԺ.2017.2.24
*��    ��:
*        ����ϲ
***********************************************************************************************************/
#include<stdio.h>  
#include<cv.h>  
#include<highgui.h>  

void sum_rgb(IplImage*src, IplImage*dst)
{
	IplImage* r = cvCreateImage(cvGetSize(src), src->depth, 1);
	IplImage* g = cvCreateImage(cvGetSize(src), src->depth, 1);
	IplImage* b = cvCreateImage(cvGetSize(src), src->depth, 1);

	cvSplit(src, r, g, b, NULL);                    // cvSplit�Ǿ��зֱ���ÿ��ͨ�����൥ͨ��ͼ���ܵ�openCV�е�һ��������  

	IplImage* s = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);

	cvAddWeighted(r, 1. / 3., g, 1. / 3., 0.0, s);
	cvAddWeighted(s, 2. / 3., b, 1. / 3., 0.0, s);

	cvThreshold(s, dst, 100, 100, CV_THRESH_TRUNC); //������ֵ������  

	cvReleaseImage(&r);
	cvReleaseImage(&g);
	cvReleaseImage(&b);
	cvReleaseImage(&s);

}
//���������  
int main(int argc, char** argv)
{
	IplImage* src = cvLoadImage("C:\\Users\\Administrator\\Desktop\\aa.jpg"); //cvNamedWindow("��1��",1);  cvShowImage("��1��",src);  
	cvNamedWindow("ԭͼ", 1);
	cvShowImage("ԭͼ", src);
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