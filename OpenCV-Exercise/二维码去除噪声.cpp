//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
//int main()
//{
//	Mat src = imread("E:/opencvpicture/love2.png");
//	if (src.empty())
//	{
//		cout << "无法加载图像" << endl;
//		return -1;
//	}
//	Mat src_gary;
//	cvtColor(src, src_gary, COLOR_BGR2GRAY);
//	Mat binimg;
//	threshold(src_gary, binimg, 100, 255, CV_THRESH_BINARY);
//	imshow("二值图", binimg);
//	Mat hline = getStructuringElement(MORPH_RECT, Size(5, 1));
//	Mat hline2 = getStructuringElement(MORPH_RECT, Size(3, 1));
//	Mat vline = getStructuringElement(MORPH_RECT, Size(1, 3));
//	Mat rect = getStructuringElement(MORPH_RECT, Size(5, 5));
//	Mat rect1 = getStructuringElement(MORPH_RECT, Size(3, 3));
//	Mat result_img, temp,temp2;
//
//	dilate(binimg, temp, rect);
//	imshow("temp image", temp);
//	//
//	dilate(temp, temp2, vline);
//	imshow("temp2 image", temp2);
//	erode(temp2, result_img, vline);
//	//
//	dilate(result_img, result_img, hline);
//	erode(result_img, result_img, hline);
//	//
//	dilate(result_img, result_img, rect1);
//	erode(result_img, result_img, rect1);
//	//
//	erode(result_img, result_img, rect);
//	imshow("result image", result_img);
//	imwrite("E:/opencvpicture/love3.png", result_img);
//	waitKey();
//	return 0;
//
//}