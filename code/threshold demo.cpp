////阈值演示
//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
//Mat src;
//int threshold_value=100;
//int max_value = 255;
//int type_value = 1;
//int type_max = 4;
//void threshold_demo(int, void *);
//int main()
//{
//	src = imread("E:\\opencvpicture\\test (1).jpg");
//	Mat src_gray;
//	cvtColor(src, src_gray, COLOR_BGR2GRAY);
//	if (src.empty())
//	{
//		cout<<"图片无法加载"<<endl;
//		return 0;
//	}
//	imshow("src", src);
//	cout << "THRESH_BINARY     = 0\nTHRESH_BINARY_INV = 1\nTHRESH_TRUNC      = 2\nTHRESH_TOZERO     = 3\nTHRESH_TOZERO_INV = 4" << endl;
//	threshold_demo(0, 0);
//	createTrackbar("size", "src", &threshold_value, max_value, threshold_demo);
//	createTrackbar("type", "src", &type_value, type_max, threshold_demo);
//	waitKey();
//	return 0;
//}
//
//void threshold_demo(int, void *)
//{
//	//THRESH_BINARY     = 0
//	//THRESH_BINARY_INV = 1
//	//THRESH_TRUNC      = 2
//	//THRESH_TOZERO     = 3
//	//THRESH_TOZERO_INV = 4
//	
//	
//	Mat src_gray,src_bin,src_bin_temp;
//	cvtColor(src, src_gray, COLOR_BGR2GRAY);
//
//	//输入图像是八位的灰度图
//	threshold(src_gray, src_bin, threshold_value, 255, type_value);
//	imshow("BIN_IMG1", src_bin);
//	Mat src_canny;
//	int canny_value=50;
//
//	adaptiveThreshold(src_gray, src_bin_temp, UCHAR_MAX, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY,351,11);
//	imshow("BIN_IMG2", src_bin_temp);
//
//	Canny(src_bin, src_canny, canny_value, canny_value * 3);
//	imshow("边缘图",src_canny);
//
//	//Mat temp;
//	//src_bin_temp.copyTo(temp, src_bin);
//	//imshow("BIN_IMG", temp);
//
//}