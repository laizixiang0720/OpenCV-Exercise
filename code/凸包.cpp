//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
//Mat src,src_gray,src_bin;
//int threshold_value = 75;
//int max_value = 155;
//void Threshold_Callback(int, void*);
//int main()
//{
//	
//	src = imread("E:/opencvpicture/Back_Projection_Theory2.jpg");
//	imshow("input image", src);
//	cvtColor(src, src_gray, COLOR_RGB2GRAY);
//	blur(src_gray, src_gray, Size(3, 3));
//	Threshold_Callback(0, 0);
//	createTrackbar("ãÐÖµ1", "input image", &threshold_value, 255, Threshold_Callback);
//	createTrackbar("ãÐÖµ2", "input image", &max_value, 255, Threshold_Callback);
//	waitKey(0);
//	return 0;
//}
//void Threshold_Callback(int, void*)
//{
//	vector<vector<Point>> contours;
//	vector<Vec4i> hierachy;
//	threshold(src_gray, src_bin, threshold_value, 255, THRESH_BINARY);	
//	imshow("src_bin", src_bin);
//	Mat src_canny;
//	Canny(src_bin, src_canny, threshold_value, max_value);
//	imshow("src_canny", src_canny);
//	findContours(src_bin, contours, hierachy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
//	vector<vector<Point>> convexs(contours.size());
//	for (size_t i = 0; i < contours.size(); i++)
//	{
//		convexHull(contours[i], convexs[i]);
//	}
//	Mat dst = Mat::zeros(src.size(), CV_8UC3);
//	for (size_t j = 0; j < contours.size(); j++)
//	{
//		drawContours(dst, contours, j, Scalar(0, 0, 255), 1, LINE_AA, hierachy, 0, Point(0, 0));
//		drawContours(dst, convexs, j, Scalar(0, 255, 0), 1, LINE_AA, hierachy, 0, Point(0, 0));
//	}
//	imshow("convex hull demo", dst);
//}