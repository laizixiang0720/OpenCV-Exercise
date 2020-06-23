//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
//void drawRandomLines(Mat &image)
//{
//	RNG rng(0xffffff);
//	Point pt1, pt2;
//	int r, g, b;
//	for (int i = 0; i < 100000; i++)
//	{
//		pt1.x = rng.uniform(0, image.cols);
//		pt1.y = rng.uniform(0, image.rows);
//		pt2.x = rng.uniform(0, image.cols);
//		pt2.y = rng.uniform(0, image.rows);
//		r = rng.uniform(0, UCHAR_MAX);
//		g = rng.uniform(0, UCHAR_MAX);
//		b = rng.uniform(0, UCHAR_MAX);
//		line(image, pt1, pt2, Scalar(r, g, b), 1, LINE_8);
//		
//		waitKey(2);
//		imshow("drawrandomLines", image);
//	}
//}
//int main()
//{
//	Size(100,100);
//	Mat canvas(800, 800, CV_8UC3);
//	Mat image;
//	image.create(Size(600, 600), CV_8UC3);
//	image= Scalar(255, 255, 255);
//	char c = 75;
//	string a = "hello";
//	a = a + c;
//	canvas = Scalar(255, 255, 255);
//	putText(canvas, a, Point(0, 66), CV_FONT_HERSHEY_COMPLEX,3, 1,LINE_4);
//	drawRandomLines(image);
//	imshow("canvas", canvas);
//	waitKey(0);
//	return 0;
//}