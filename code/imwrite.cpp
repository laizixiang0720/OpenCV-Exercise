////LAI 图片读取和图片保存
//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
//int main()
//{
//	Mat src = imread("E:\\opencvpicture\\binne.png");
//	namedWindow("输出窗口", CV_WINDOW_AUTOSIZE);
//	imshow("输出窗口", src);
//	Mat output;
//
//	cvtColor(src, output, COLOR_BGR2GRAY);
//	cout << output.channels() << endl;
//	imwrite("e:/opencvpicture/binne.png", output);
//	imshow("输出窗口2", output);
//	waitKey(0);
//	return 0;
//}