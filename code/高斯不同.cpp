////灰度增强，角点检测
//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//	Mat src = imread("E:/opencvpicture/mao.jpg");
//	if (!src.data)
//	{
//		cout << "无法加载图片" << endl;
//		return -1;
//	}
//	Mat src_gray, g1, g2,dogimg;
//	cvtColor(src, src_gray, COLOR_BGR2GRAY);
//	GaussianBlur(src_gray, g1, Size(3, 3),0);
//	GaussianBlur(g1, g2, Size(3, 3), 0);
//	/*dogimg = g1 - g2;*/
//	subtract(g1, g2,dogimg);
//	normalize(dogimg, dogimg, 0, 255, NORM_MINMAX);
//	imshow("dogim", dogimg);
//	waitKey(0);
//	return 0;
//}