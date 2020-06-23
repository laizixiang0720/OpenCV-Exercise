//#include<opencv2/opencv.hpp>
//#include<iostream>
//using namespace cv;
//using namespace std;
//int main(int argc, int** argv)
//{
//	Mat src = imread("E:\\opencvpicture\\0.jpg");
//	Mat r2,r3;
//	CascadeClassifier detector;
//	detector.load("C:/opencv/build/etc/haarcascades/haarcascade_frontalface_alt_tree.xml");
//	vector<Rect> faces;
//	imshow("face", src);
//	detector.detectMultiScale(src, faces, 1.1, 2, 0, Size(20, 20));
//	size_t t = 0;
//	for (; t < faces.size(); t++)
//	{
//	}
//	rectangle(src, faces[t - 1], Scalar(0, 0, 225), 1, 8);
//	imshow("face detector", src);
//	r2 = src(faces[t - 1]);
//	try {
//		bilateralFilter(r2, r3, -1,50 ,3);
//	}
//	catch (const std::exception& ex){
//		cout << ex.what() << endl;
//	}
//	Mat kernel = (Mat_<int>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
//	filter2D(r3,r3, -1, kernel);
//	r3.copyTo(r2);
//	imshow("b", src);
//	waitKey(0);
//	return 0;
//}