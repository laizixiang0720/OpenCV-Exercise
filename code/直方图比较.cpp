////ֱ��ͼ�Ƚ�
//#include<opencv2/opencv.hpp>
//#include<iostream>
//#include<math.h>
//using namespace cv;
//using namespace std;
//
//int main()
//{
//	Mat base, test1, test2;
//	//��ȡ���űȽ�ͼ
//	base = imread("E:/opencvpicture/1_gray.png");
//	test1 = imread("E:/opencvpicture/1.png");
//	test2 = imread("E:/opencvpicture/1_noise.png");
//	//չʾ����ͼƬ
//	imshow("base", base);
//	imshow("test1", test1);
//	imshow("test2", test2);
//	//��ͼƬ��rbgɫ�ʿռ�ת����hsv
//	//
//	cvtColor(base, base, COLOR_BGR2HSV);
//	cvtColor(test1, test1, COLOR_BGR2HSV);
//	cvtColor(test2, test2, COLOR_BGR2HSV);
//	//���ò���
//	int h_bins = 50;
//	int s_bins = 60;
//	float h_ranges[] = { 0,180 };
//	float s_ranges[] = { 0,256 };
//	const float* ranges[] = { h_ranges ,s_ranges };
//	int histSize[] = { h_bins, s_bins };
//	int channels[] = { 0,1 };
//	MatND hist_base,hist_test1,hist_test2;
//	//����ֱ��ͼ
//	calcHist(&base,1,channels,Mat(),hist_base,2, histSize,ranges,true,false);
//	calcHist(&test1, 1, channels, Mat(), hist_test1, 2, histSize, ranges, true, false);
//	calcHist(&test2, 1, channels, Mat(), hist_test2, 2, histSize, ranges, true, false);
//	//�����ݽ��й�һ��
//	normalize(hist_base, hist_base,0,1,NORM_MINMAX);	
//	normalize(hist_test1, hist_test1, 0, 1, NORM_MINMAX);
//	normalize(hist_test2, hist_test2, 0, 1, NORM_MINMAX);
//	//��ñȽϵĽ��
//	double base_base = compareHist(hist_base, hist_base, CV_COMP_BHATTACHARYYA);
//	double base_test1 = compareHist(hist_base, hist_test1, CV_COMP_BHATTACHARYYA);
//	double base_test2 = compareHist(hist_base, hist_test2, CV_COMP_BHATTACHARYYA);
//	//��ӡ���
//	printf("base��base���Ƚϵ�ֵ%f\n", base_base);
//	printf("test1��base���Ƚϵ�ֵ%f\n", base_test1);
//	printf("test2��base���Ƚϵ�ֵ%f\n", base_test2);
//	waitKey(0);
//	return 0;
//	
//}