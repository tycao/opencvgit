#include<opencv2\opencv.hpp>  
#include<opencv2\imgproc\imgproc.hpp>  
#include<opencv2\imgproc\imgproc_c.h>  
#include<opencv2\highgui\highgui.hpp>  

int main()
{
	//��1������ԭͼ  
	IplImage* srcImg = cvLoadImage("e:\\IMG_2576.JPG");
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