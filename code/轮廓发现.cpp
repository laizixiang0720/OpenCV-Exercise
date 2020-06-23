////轮廓发现
//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
//int threshold_value = 152;
//int canny_value = 156;
//
//int main()
//{
//	Mat src = imread("E:/opencvpicture/test (1).jpg");
//	imshow("原图", src);
//
//	Mat src_blur;
//	blur(src, src_blur, Size(3, 3));
//
//	Mat src_blur_gray;
//	cvtColor(src_blur, src_blur_gray, COLOR_BGR2GRAY);
//	imshow("降噪灰度图", src_blur_gray);
//
//	Mat src_blur_gray_bin;
//	threshold(src_blur_gray, src_blur_gray_bin,140, 255, THRESH_BINARY);
//	imshow("降噪灰度二值化图", src_blur_gray_bin);
//
//	Mat src_canny;
//	Canny(src_blur_gray_bin, src_canny, canny_value, canny_value * 3);
//	imshow("边缘图", src_canny);
//
//	waitKey(0);
//	return 0;
//}
//
//
