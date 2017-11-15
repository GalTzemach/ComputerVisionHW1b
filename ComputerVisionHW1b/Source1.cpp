//// OpenCV_Helloworld.cpp : Defines the entry point for the console application.
//// Created for build/install tutorial, Microsoft Visual C++ 2010 Express and OpenCV 3.1.0
//
//#include "opencv2/core.hpp"
//#include "opencv2/imgproc.hpp"
//#include "opencv2/highgui.hpp"
////#include <opencv/cv.h>
//// #include <opencv/cxcore.h>
//// #include <opencv/highgui.h>
//using namespace cv;
//
////#define IMG
//#ifdef IMG
//
//int main()
//{
//	IplImage* img = cvLoadImage("funnyCat.jpg");
//	cvNamedWindow("Image:", 1);
//	cvNamedWindow("Gray Image:", 2);
//	Mat im_gray = imread("funnyCat.jpg", CV_LOAD_IMAGE_GRAYSCALE);
//
//	imshow("Gray Image:", im_gray);
//	cvShowImage("Image:", img);
//	cvWaitKey();
//	cvDestroyWindow("Image:");
//
//	cvReleaseImage(&img);
//	im_gray.release();
//	return 0;
//}
//
//#else
//
//#include <opencv\cv.h>
//#include <opencv\highgui.h>
//
//int main()
//{
//	//create Matrix to store image 
//	Mat image;
//
//	// initialize capture
//
//	VideoCapture cap;
//	cap.open(0);
//
//	// create window to show image 
//	namedWindow("window", CV_WINDOW_AUTOSIZE);
//
//	while (true) {
//
//		// copy webcam stream to image	 
//		cap >> image;
//
//		// print image to screen 
//		imshow("window", image);
//
//		// delay 33ms 
//		waitKey(33);
//	}
//
//	image.release();
//	return 0;
//}
//
//#endif