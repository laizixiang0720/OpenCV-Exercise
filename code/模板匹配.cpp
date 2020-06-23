////模板匹配
//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
////定义方法编号
//int match_method = TM_SQDIFF;
//int  max_method = TM_CCOEFF_NORMED;
////
//Mat src, temp;
//void Match_Demo(int, void*);
//int main()
//{
//	src = imread("E:/opencvpicture/4231.jpg");
//	temp = imread("E:/opencvpicture/delta_002.jpg");
//	Match_Demo(0, 0);
//	createTrackbar("method", "result image", &match_method, max_method, Match_Demo);
//	waitKey(0);
//	return 0;
//}
//void Match_Demo(int, void*)
//{
//	int width = src.cols - temp.cols + 1;
//	int height = src.rows - temp.rows + 1;
//	Mat result(width, height, CV_32FC1);
//	matchTemplate(src, temp, result, match_method);
//	normalize(result, result, 0, 1, NORM_MINMAX);
//
//	Point maxloc;
//	Point minloc;
//	double min, max;
//	Point tmeploc;
//	minMaxLoc(result, &min, &max, &minloc, &maxloc);
//
//	if (match_method == TM_SQDIFF || match_method == TM_SQDIFF_NORMED)
//	{
//		tmeploc = minloc;
//	}
//	else
//	{
//		tmeploc = maxloc;
//	}
//	Mat dst;
//	dst = src.clone();
//	//
//	rectangle(dst, Rect(tmeploc.x, tmeploc.y, temp.cols, temp.rows), Scalar(0, 0, 255), 1, LINE_AA);
//	rectangle(result, Rect(tmeploc.x, tmeploc.y, temp.cols, temp.rows), Scalar(0, 0, 255), 1, LINE_AA);
//	imshow("result image", result);
//	imshow("template match-demo", dst);
//}