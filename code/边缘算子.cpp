//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
//int main()
//{
//	Mat src;
//	src = imread("E:/opencvpicture/1.png");
//	Mat dst,dst1;
//	cvtColor(src, dst, COLOR_BGR2GRAY);
//	imshow("�Ҷ�ͼ", dst);
//	Mat temp = Mat::zeros(Size(src.cols, src.rows), CV_16S);
//	imshow("temp", temp);
//
//	//���Լ�дһ��sobel���ӵĺ���(ʧ���˩c(*��>��<)o�b)
//	//ԭ�����:����Ϊsobel����ֻ��sobel���Ӻ�filter2D�򵥵Ľ��
//	/*int m;
//	int  x = 0;
//	int sum = 0;
//	for (int i = 1; i < dst.rows-1; i++)
//	{
//		for (int j = 1; j < dst.cols-1; j++)
//		{
//			sum = -1 * dst.at<uchar>(i - 1, j - 1);
//			sum += dst.at<uchar>(i - 1, j + 1);
//			sum += -2 * dst.at<uchar>(i , j - 1);
//
//
//			sum += 2 * dst.at<uchar>(i , j + 1);
//			sum += -1 * dst.at<uchar>(i + 1, j - 1);
//			sum += dst.at<uchar>(i + 1, j + 1);
//				
//			temp.at<short>(i, j) =sum;
//		}
//	}*/
//	imshow("2", temp);
//	convertScaleAbs(temp, dst1);
//	imshow("1", dst1);
//	Mat mask = (Mat_<int>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);
//	filter2D(dst, temp, -1, mask);
//	imshow("1322", temp);
//	waitKey();
//	return 0;
//}