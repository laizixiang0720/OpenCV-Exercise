//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
//int main()
//{
//	VideoCapture cam(1);
//
//	if (!cam.isOpened())
//	{
//		cout << "无法打开摄像头" << endl;
//	}
//	Mat frame, frame_canny, frame_blur, frame_gray, frame_bin;
//	vector<Vec4f> plines;
//	vector<Vec3f> circles;
//	Vec3f c3;
//	Vec4f h1;
//	int threshold_value = 100;
//	while (waitKey(5) != 27) {
//		cam.read(frame);
//		if (frame.empty()) {
//			cout << "图像无法输出" << endl;
//			return -1;
//		}
//		imshow("SRC", frame);
//		//中值滤波
//		medianBlur(frame, frame_blur, 3);
//		imshow("frame_blur", frame_blur);
//		//将图像转化为灰度图
//		cvtColor(frame_blur, frame_gray, COLOR_BGR2GRAY);
//		imshow("frame_gray", frame_gray);
//		//二值化
//		threshold(frame_gray, frame_bin, 175, 255, CV_THRESH_BINARY);
//		imshow("frame_bin", frame_bin);
//		//边缘检测
//		Canny(frame_gray, frame_canny, threshold_value, threshold_value * 2);
//		imshow("Canny", frame_canny);
//		//霍夫直线检测
//		HoughLinesP(frame_canny, plines, 1, CV_PI / 180, 20, 80, 20);
//		//霍夫圆检测
//		HoughCircles(frame_canny, circles, HOUGH_GRADIENT, 1, 50, threshold_value * 2, 50, 10, 200);
//
//
//		for (size_t i = 0; i < plines.size(); i++)
//		{
//			h1 = plines[i];	
//				line(frame, Point(h1[0], h1[1]), Point(h1[2], h1[3]), Scalar(0, 0, 255), 1, CV_AA);			
//		}
//		for (size_t j = 0; j < circles.size(); j++)
//		{
//			c3 = circles[j];
//				circle(frame, Point(c3[0], c3[1]), c3[2], Scalar(255, 0, 0), 1, LINE_AA);						
//		}
//		imshow("霍夫变换直线", frame);
//	}
//	return 0;
//}