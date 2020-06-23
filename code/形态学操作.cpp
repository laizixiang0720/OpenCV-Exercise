//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
//int element_size = 1;
//int element_size1 = 1;
//int element_size2 = 1;
//int element_size3 = 1;
//int element_size4 = 1;
//
//void dilate_demo(int, void*);
//Mat src = imread("E:/opencvpicture/mao.jpg");
////Mat src = imread("E:/opencvpicture/binne.png");
//int main()
//{
//
//	int max_size = 10;
//	imshow("原图", src);
//	dilate_demo(0, 0);
//	//可调整的参数的
//	createTrackbar("element size", "膨胀操作", &element_size, max_size, dilate_demo);
//	createTrackbar("element size", "腐蚀操作", &element_size1, max_size, dilate_demo);
//	createTrackbar("element size", "形态学开操作", &element_size2, max_size, dilate_demo);
//	createTrackbar("element size", "形态学闭操作", &element_size3, max_size, dilate_demo);
//	createTrackbar("element size", "形态学梯度操作", &element_size4, max_size, dilate_demo);
//	waitKey(0);
//	return 0;
//}
//
//void dilate_demo(int, void*)
//{
//	int s = element_size * 2 + 1;
//	int s1 = element_size1 * 2 + 1;
//	int s2 = element_size2 * 2 + 1;
//	int s3 = element_size3 * 2 + 1;
//	int s4 = element_size4 * 2 + 1;
//	//定义结构元素
//	Mat structe_element = getStructuringElement(MORPH_RECT, Size(s, s));
//	Mat structe_element1 = getStructuringElement(MORPH_RECT, Size(s1, s1));
//	Mat structe_element2 = getStructuringElement(MORPH_RECT, Size(s2, s2));
//	Mat structe_element3 = getStructuringElement(MORPH_RECT, Size(s3, s3));
//	Mat structe_element4 = getStructuringElement(MORPH_RECT, Size(s4, s4));
//	Mat dst,dst1,dst2,dst3,dst4;
//	//膨胀操作
//	dilate(src, dst, structe_element);
//	//腐蚀操作
//	erode(src, dst1, structe_element1);
//	//形态学开操作
//	morphologyEx(src, dst2, CV_MOP_OPEN, structe_element2);
//	//形态学闭操作
//	morphologyEx(src, dst3, CV_MOP_CLOSE, structe_element3);
//	//形态学梯度操作
//	morphologyEx(src, dst4, CV_MOP_GRADIENT, structe_element4);
//	//显示图片
//	imshow("膨胀操作", dst);
//	imshow("腐蚀操作", dst1);
//	imshow("形态学开操作", dst2);
//	imshow("形态学闭操作", dst3);
//	imshow("形态学梯度操作", dst4);
//	return;
//}