//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
//Mat src, hsv, hue;
////binsָ�Ľ������ռ��ȡֵ��Χ�ֳɶ��ٸ�С������
//int bins = 12;
//void Hist_And_Backprojection(int, void*);
//int main()
//{
//	src = imread("E:/opencvpicture/Back_Projection_Theory2.jpg");
//	if (src.empty())
//	{
//		cout << "ͼƬ����ʧ��" << endl;
//		return -1;
//	}
//	
//	cvtColor(src, hsv, COLOR_BGR2HSV);
//	hue.create(src.size(),hsv.depth());
//	int nchannels[] = { 0,0 };
//	mixChannels(&hsv, 1, &hue,1,nchannels,1 );
//	imshow("input image", src);
//	Hist_And_Backprojection(0,0);
//	createTrackbar("Histogram Bins","input image",&bins,180, Hist_And_Backprojection);
//	
//	waitKey(0);
//	return 0;
//}
//
//void Hist_And_Backprojection(int, void*)
//{
//	//rangeָ����ÿ�������ռ��ȡֵ��Χ
//	//���������������ɫ�ʿռ��rgb�ռ�ת������hsv�ռ��У�
//	//����Ϊ�ǽ�hsv�ռ��е�hͨ��ȡ��������hͨ����ȡֵ��Χ��0-180
//	//����range�ķ�Χ��0-180
//	float range[] = { 0,180 };
//	const float *histRanges = range;
//	Mat h_hist;
//	calcHist(&hue, 1, 0, Mat(), h_hist, 1, &bins, &histRanges, true, false);
//	normalize(h_hist, h_hist, 0, 255, NORM_MINMAX);
//	Mat backPrjImage;
//	calcBackProject(&hue, 1, 0, h_hist, backPrjImage, &histRanges);
//	
//
//	int hist_h = 400;
//	int hist_w = 400;
//	Mat histImage(hist_w, hist_h, CV_8UC3, Scalar(0, 0, 0));
//	int bin_w = cvRound(hist_w / bins);
//	for (size_t i = 1; i < bins; i++)
//	{
//		rectangle(histImage, Point((i - 1)*bin_w, hist_h - cvRound(h_hist.at<float>(i - 1) * (400 / 255))),
//			Point(i*bin_w, hist_h), Scalar(0, 0, 255),-1,LINE_AA);
//	}
//	imshow("BackProj", backPrjImage);
//	imshow("histImage", histImage);
//	return ;
//}