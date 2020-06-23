////直方图比较
//#include<opencv2/opencv.hpp>
//#include<iostream>
//#include<math.h>
//using namespace cv;
//using namespace std;
//
//int main()
//{
//	Mat base, test1, test2;
//	//读取三张比较图
//	base = imread("E:/opencvpicture/1_gray.png");
//	test1 = imread("E:/opencvpicture/1.png");
//	test2 = imread("E:/opencvpicture/1_noise.png");
//	//展示三张图片
//	imshow("base", base);
//	imshow("test1", test1);
//	imshow("test2", test2);
//	//将图片从rbg色彩空间转换到hsv
//	//
//	cvtColor(base, base, COLOR_BGR2HSV);
//	cvtColor(test1, test1, COLOR_BGR2HSV);
//	cvtColor(test2, test2, COLOR_BGR2HSV);
//	//设置参数
//	int h_bins = 50;
//	int s_bins = 60;
//	float h_ranges[] = { 0,180 };
//	float s_ranges[] = { 0,256 };
//	const float* ranges[] = { h_ranges ,s_ranges };
//	int histSize[] = { h_bins, s_bins };
//	int channels[] = { 0,1 };
//	MatND hist_base,hist_test1,hist_test2;
//	//计算直方图
//	calcHist(&base,1,channels,Mat(),hist_base,2, histSize,ranges,true,false);
//	calcHist(&test1, 1, channels, Mat(), hist_test1, 2, histSize, ranges, true, false);
//	calcHist(&test2, 1, channels, Mat(), hist_test2, 2, histSize, ranges, true, false);
//	//对数据进行归一化
//	normalize(hist_base, hist_base,0,1,NORM_MINMAX);	
//	normalize(hist_test1, hist_test1, 0, 1, NORM_MINMAX);
//	normalize(hist_test2, hist_test2, 0, 1, NORM_MINMAX);
//	//获得比较的结果
//	double base_base = compareHist(hist_base, hist_base, CV_COMP_BHATTACHARYYA);
//	double base_test1 = compareHist(hist_base, hist_test1, CV_COMP_BHATTACHARYYA);
//	double base_test2 = compareHist(hist_base, hist_test2, CV_COMP_BHATTACHARYYA);
//	//打印结果
//	printf("base和base所比较的值%f\n", base_base);
//	printf("test1和base所比较的值%f\n", base_test1);
//	printf("test2和base所比较的值%f\n", base_test2);
//	waitKey(0);
//	return 0;
//	
//}