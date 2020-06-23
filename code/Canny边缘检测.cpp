//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
//
//int value = 30;
//int main()
//{
//	Mat src = imread("E:/opencvpicture/1.png");
//	if (!src.data)
//	{
//		cout << "ÎÞ·¨¼ÓÔØÍ¼Æ¬" << endl;
//	}
//	Mat Operator = (Mat_<int>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
//	filter2D(src, src, -1, Operator);
//	imshow("src", src);
//	Mat src_blur;
//	GaussianBlur(src, src_blur, Size(3, 3), 0);
//	Mat src_gray;
//	cvtColor(src_blur, src_gray, COLOR_BGR2GRAY);
//	imshow("src_gray", src_gray);
//	Mat edge_output;
//	Canny(src_gray, edge_output, value, value * 2, 3, false);
//	imshow("edge_output", edge_output);
//	Mat Final_Results;
//	Final_Results.create(src.size(), src.type());
//	Final_Results = Scalar(255, 255, 255);
//	src.copyTo(Final_Results, edge_output);
//	imshow("Final_Results", Final_Results);
//	waitKey(0);
//	return 0;
//}