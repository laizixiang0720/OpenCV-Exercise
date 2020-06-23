//#include<iostream>
//#include<opencv2/opencv.hpp>
//using namespace std;
//using namespace cv;
//Mat src, gray_src, drawImg;
//int threshold_v = 170;
//int threshold_max = 255;
//RNG rng(1234);
//string output_win = "rectangle_demo";
//void Contours_callback(int, void*);
//int main()
//{
//	src = imread("E:/opencvpicture/hot air balloon.jpg");
//	if (src.empty()) {
//		cout << "could not load image.." << endl;
//		return -1;
//	}
//	cvtColor(src, gray_src, CV_BGR2GRAY);
//	blur(gray_src, gray_src, Size(3, 3));
//	string source_win = "input image";
//	imshow(source_win, src);
//	Contours_callback(0, 0);
//	createTrackbar("Threshold Value:", output_win, &threshold_v,threshold_max, Contours_callback);
//
//	waitKey();
//	return 0;
//
//}
//void Contours_callback(int, void*)
//{
//	Mat binary_output;
//	vector<vector<Point>> contours;
//	vector<Vec4i> hierachy;
//	threshold(gray_src, binary_output, threshold_v, threshold_max, THRESH_BINARY);
//	findContours(binary_output, contours, hierachy, RETR_TREE, CHAIN_APPROX_SIMPLE);
//	vector<vector<Point>> contours_ploy(contours.size());
//	vector<Rect> ploy_rects(contours.size());
//	vector<Point2f> css(contours.size());
//	vector<float> radius(contours.size());
//
//	vector<RotatedRect>minRects(contours.size());
//	vector<RotatedRect>myelipse(contours.size());
//
//	for (size_t i = 0; i < contours.size(); i++)
//	{
//		approxPolyDP(Mat(contours[i]), contours_ploy[i], 3, true);
//		ploy_rects[i] = boundingRect(contours_ploy[i]);
//		if (contours_ploy[i].size() > 5)
//		{
//			myelipse[i] = fitEllipse(contours_ploy[i]);
//			minRects[i] = minAreaRect(contours_ploy[i]);
//		}
//	}
//	drawImg = Mat::zeros(src.size(), src.type());
//	Point2f pts[4];
//	for (size_t t = 0; t < contours.size(); t++)
//	{
//		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
//		if (contours_ploy[t].size() > 5)
//		{
//			ellipse(drawImg, myelipse[t], color, 1, 8);
//			minRects[t].points(pts);
//			for (int r = 0; r < 4; r++) {
//				line(drawImg,pts[r] ,pts[(r + 1) % 4], color, 1, 8);
//			}
//		}
//	}
//	imshow(output_win, drawImg);
//	return;
//
//}