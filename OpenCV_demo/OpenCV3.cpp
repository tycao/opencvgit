    /********************************************************************************************************** 
    *文件说明: 
    *        基于OpenCv的阈值分割算法 
    *开发环境: 
    *        win7+vs2010+opencv2.4.8 
    *时间地点: 
    *        陕西师范大学.2017.2.24 
    *作    者: 
    *        李丽  
    ***********************************************************************************************************/  
    #include<stdio.h>  
    #include<cv.h>  
    #include<highgui.h>  
      
    void sum_rgb(IplImage*src,IplImage*dst)  
    {  
        IplImage* r = cvCreateImage( cvGetSize(src),src->depth,1);  
        IplImage* g = cvCreateImage( cvGetSize(src),src->depth,1);  
        IplImage* b = cvCreateImage( cvGetSize(src),src->depth,1);  
      
        cvSplit(src,r,g,b,NULL);                    // cvSplit是具有分别复制每个通道到多单通道图像功能的openCV中的一个函数。  
      
        IplImage* s = cvCreateImage( cvGetSize(src),IPL_DEPTH_8U,1);  
      
        cvAddWeighted(r,1./3.,g,1./3.,0.0,s);  
        cvAddWeighted(s,2./3.,b,1./3.,0.0,s);  
          
        cvThreshold(s,dst,100,100,CV_THRESH_TRUNC); //进行阈值化处理  
      
        cvReleaseImage(&r);  
        cvReleaseImage(&g);  
        cvReleaseImage(&b);  
        cvReleaseImage(&s);  
      
    }  
    //主函数入口  
    int main(int argc,char** argv)  
    {  
        IplImage* src = cvLoadImage(argv[1]); //cvNamedWindow("【1】",1);  cvShowImage("【1】",src);  
        cvNamedWindow("原图",1);  
        cvShowImage("原图",src);  
        IplImage* dst = cvCreateImage( cvGetSize(src),src->depth,1);  
        sum_rgb(src,dst);  
      
        cvNamedWindow(argv[1],1);  
        cvShowImage(argv[1],dst);  
        while(1)  
        {  
            if((cvWaitKey(10)&0x7f)==27)break;  
        }  
        cvDestroyWindow(argv[1]);  
        cvReleaseImage(&src);  
        cvReleaseImage(&dst);  
    }  