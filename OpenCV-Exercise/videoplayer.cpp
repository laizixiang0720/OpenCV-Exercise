//#include<opencv2/opencv.hpp>
//#include<iostream>
//using namespace cv;
//using namespace std;
//
//int main()
//{
//	VideoCapture video;
//	VideoWriter vw;
//
//	//$加载测试用的视频
//	video.open("D:/Download/常规/KDA+Offical+Music+Video.4K+Ver.webm");
//	//$判断是否加载视频成功
//	if (!video.isOpened())
//	{
//		cout << "视频打开失败" << endl;
//		return -1;
//	}
//	Mat frame, r1, r2;
//	//$读取一张图片作为水印
//	r1 = imread("E:/opencvpicture/train.jpg");
//	int rows, cols;
//	rows = r1.rows;
//	cols = r1.cols;
//	//$获取fps用来计算等待时间
//	int fps = video.get(CAP_PROP_FPS);
//	int s = 1000 / fps;
//	int time;
//	int width, height;
//	//$获取视频的宽和高
//	width = video.get(CAP_PROP_FRAME_WIDTH);
//	height = video.get(CAP_PROP_FRAME_HEIGHT);
//	//$获取视频总帧数，并用
//	int fcount = video.get(CAP_PROP_FRAME_COUNT);
//	time = fcount / fps;
//	//
//	cout << fps << "fps" << endl;
//	cout << fcount << "帧" << endl;
//	cout << time << "s" << endl;
//	int count = 1;
//
//	while (true)
//	{
//		
//		video >> frame;
//		
//		if (frame.empty())
//		{
//			break;
//		}
//
//		imshow("video", frame);
//
//		if (waitKey(s) == 27)
//			break;
//	}
//	return 0;
//}