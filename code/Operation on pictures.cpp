////对图片的操作
//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
//void PrintMs(const char *text = "")
//{
//	static long long last = 0;
//	long long cur = getTickCount();
//	if (last == 0)
//	{
//		last = cur;
//		return;
//	}
//	long long ms = 0;
//	ms = ((double)(cur - last) / getTickFrequency()) * 1000;
//	if (*text != 0)
//	{
//		printf("%s = %dms\n", text, ms);
//	}
//	last = getTickCount();
//}
//
//int main()
//{
//	Mat src(768, 1366, CV_8UC4);
//	cout << "src.elemSize:" << src.elemSize() << endl;
//	cout << "src.elemSize1:" << src.elemSize1() << endl;
//	cout << "src.step:" << src.step << endl;
//	cout << "src.step1:" << src.step1() << endl;
//	cout << "src.channels():" << src.channels() << endl;
//	cout << "src.cols:" << src.cols << endl;
//	cout << "src.depth:" << src.depth() << endl;
//	for (int i = 0; i < src.rows; ++i)
//	{
//		for (int j = 0; j < src.cols; ++j)
//		{
//			Vec4b& bgra = src.at<Vec4b>(i, j);
//			bgra[0] = UCHAR_MAX; // Blue
//			bgra[1] = saturate_cast<uchar>((float(src.cols - j)) / ((float)src.cols) * UCHAR_MAX); // Green
//			bgra[2] = saturate_cast<uchar>((float(src.rows - i)) / ((float)src.rows) * UCHAR_MAX); // Red
//			bgra[3] = saturate_cast<uchar>(0.5 * (bgra[1] + bgra[2])); // Alpha
//		}
//	}
//	printf("%d\n", *src.data);
//	imshow("窗口1", src);
//	imwrite("E:/opencvpicture/11.png", src);
//	waitKey(0);
//	return 0;
//}

