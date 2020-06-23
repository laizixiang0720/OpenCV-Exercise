//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
//int main()
//{
//	Mat src;
//	//加载图片
//	src = imread("E:/opencvpicture/1.png");
//	if (src.empty())
//	{
//		printf("could not load image...\n");
//		return -1;
//	}
//	imshow("原图", src);
//
//	int histSize = 256;
//	float range[] = { 0,256 };
//	const float *histRange = range;
//	vector<Mat> bgr_channel;
//	Mat b_hist, r_hist, g_hist;
//	int hist_h = 400;
//	int hist_w = 512;
//	int bin_w = hist_w / histSize;
//	Mat Histogram;
//	Histogram = Mat(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));
//	split(src, bgr_channel);
//	//计算直方图
//	calcHist(&bgr_channel[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, true, false);
//	calcHist(&bgr_channel[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, true, false);
//	calcHist(&bgr_channel[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, true, false);
//	//进行归一化
//	normalize(b_hist, b_hist, 0, hist_h, NORM_MINMAX);
//	normalize(g_hist, g_hist, 0, hist_h, NORM_MINMAX);
//	normalize(r_hist, r_hist, 0, hist_h, NORM_MINMAX);
//	//绘制出
//	for (int i = 1; i < histSize; i++)
//	{
//		line(Histogram, Point((i - 1)*bin_w, hist_h - cvRound(b_hist.at<float>(i - 1)))
//			, Point(i*bin_w, hist_h - cvRound(b_hist.at<float>(i))), Scalar(255, 0, 0), 1, LINE_AA);
//
//		line(Histogram, Point((i - 1)*bin_w, hist_h - cvRound(g_hist.at<float>(i - 1)))
//			, Point(i*bin_w, hist_h - cvRound(g_hist.at<float>(i))), Scalar(0, 255, 0), 1, LINE_AA);
//
//		line(Histogram, Point((i - 1)*bin_w, hist_h - cvRound(r_hist.at<float>(i - 1)))
//			, Point(i*bin_w, hist_h - cvRound(r_hist.at<float>(i))), Scalar(0, 0, 255), 1, LINE_AA);
//	}
//	imshow("折线图", Histogram);
//	waitKey(0);
//}