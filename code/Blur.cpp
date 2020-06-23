//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
////
//void myblur(Mat &src, Mat &dst)
//{
//	
//	dst.create(src.size(), src.type());
//	for (int row = 1; row < src.rows - 1; row++)
//	{
//		for (int col = 1; col < src.cols - 1; col++)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				int sum,Pixel;
//				sum = 0;
//				Pixel = 0;
//				int data[8];
//				data[0] = src.ptr<uchar>(row - 1, col - 1)[i];
//				data[1] = src.ptr<uchar>(row - 1, col)[i];
//				data[2] = src.ptr<uchar>(row - 1, col + 1)[i];
//				data[3] = src.ptr<uchar>(row, col - 1)[i];
//				data[4] = src.ptr<uchar>(row, col + 1)[i];
//				data[5] = src.ptr<uchar>(row + 1, col - 1)[i];
//				data[6] = src.ptr<uchar>(row + 1, col)[i];
//				data[7] = src.ptr<uchar>(row + 1, col + 1)[i];
//				for (int j = 0; j < 8; j++)
//				{
//					sum += data[j];
//				}
//				Pixel = sum / 8;
//				dst.ptr<uchar>(row, col)[i] = Pixel;
//			}
//			
//		}
//	}
//}
//
//int main()
//{
//	Mat src = imread("E:/opencvpicture/1.png");
//	Mat dst,dst2,dst3,dst4;
//	myblur(src, dst);
//	//均值滤波
//	blur(src, dst2, Size(3,3),Point(-1,-1));
//	//高斯滤波
//	//高斯滤波比均值滤波保留了图像的更多细节
//	GaussianBlur(src, dst3, Size(3,3),11,11);
//	bilateralFilter(src, dst4, -1,50, 3);
//	imshow("src", src);
//	imshow("myblur", dst);
//	imshow("blur", dst2);
//	imshow("GaussianBlur", dst3);
//	imshow("bilateralFilter", dst4);
//	waitKey();
//	return 0;
//}