 ////两幅图片叠加

 //#include<opencv2/opencv.hpp>
 //#include<iostream>

 //using namespace cv;
 //using namespace std;

 ////准备自己写一个两幅图像叠加的api
 ////void blending(Mat &src1, float alpha1, Mat &src2, float alpha2, int gamma,Mat dst)
 ////{
 ////	
 ////
 ////}
 //int main()
 //{
 //	Mat src1, src2, dst, dst2, rot, des;
 //	src1 = imread("E:/opencvpicture/train.jpg");
 //	src2 = imread("E:/opencvpicture/road.jpg");
 //	des.create(src1.rows, src1.cols * 2, src1.type());
 //	try
 //	{
 //		Mat r1 = des(Rect(0, 0, src1.cols, src1.rows));
 //		Mat r2 = des(Rect(src1.cols,0 , src1.cols, src1.rows));
 //		src1.copyTo(r1);
 //		src2.copyTo(r2);
 //	}
 //	catch (const std::exception& ex)
 //	{
 //		cout << ex.what() << endl;
 //	}

 //	float a = 0.5;
 //	addWeighted(src1, a, src2, 1 - a, 1, dst);
 //	cvtColor(src1, dst, COLOR_BGR2GRAY);
 //	cvtColor(src1, dst2, COLOR_BGR2RGB);

 //	rotate(src1, rot, ROTATE_180);
 //	imshow("src1", src1);
 //	imshow("src2", src2);
 //	imshow("dst", dst);
 //	imshow("dst2", dst2);
 //	imshow("rot", rot);
 //	imshow("des", des);
 //	waitKey(0);
 //	return 0;
 //}