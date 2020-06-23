//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
//int main()
//{
//	Mat src, dst;
//	src = imread("E:/opencvpicture/mao.jpg");
//	Mat map_x, map_y;
//	map_x = Mat(src.size(), CV_32FC1);
//	map_y = Mat(src.size(), CV_32FC1);
//	for (size_t row = 0; row < src.rows; row++)
//	{
//		for (size_t col = 0; col < src.cols; col++)
//		{
//			map_x.at<float>(row, col) = col;
//			map_y.at<float>(row, col) = src.rows - row;
//		}
//
//	}
//	remap(src, dst, map_x, map_y, INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));
//	imshow("÷ÿ”≥…‰∫ÛµƒÕºœÒ", dst);
//	waitKey(0);
//	return 0;
//}