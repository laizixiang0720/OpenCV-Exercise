//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
//int main()
//{
//	Mat src = imread("E:/opencvpicture/1.png");
//	Mat dst, dst1;
//	if (src.empty())
//	{
//		cout << "ͼƬ����ʧ��" << endl;
//		return -1;
//	}
//	imshow("ԭͼ", src);
//	//3*3��ֵ�˲�
//	Mat kernel = (Mat_<float>(3, 3) << 1, 1, 1, 1, 1, 1, 1, 1, 1) / 9;
//	filter2D(src, dst, -1, kernel);
//	//
//	imshow("�ı���ͼ��", dst);
//	int ksize = 0;
//	int count = 5;
//	while (true)
//	{
//		ksize = 3 + (count % 5) * 2 + 1;
//		Mat mask = Mat::ones(Size(ksize, ksize), CV_32F) / (ksize*ksize);
//		filter2D(src, dst1, -1, mask);
//		imshow("�ı��ͼ��", dst1);
//		if (waitKey(200) == 27)
//		{
//			break;
//		}
//		count++;
//
//	}
//	waitKey();
//}