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
//	video.open("D:/360极速浏览器下载/cf.flv");
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
//	vw.open("E:/opencvpicture/cf.mp4", VideoWriter::fourcc('h', '2', '6', '4'),
//		fps, Size(width, height));
//	while (true)
//	{
//		//$将视频流中的一帧写入到mat对象中
//		//#方法1：用重载运算符
//		video >> frame;
//		//#方法2：用VideoCapture自带read函数将内容写入frame中
//		/*if (!video.read(frame))
//		{
//			break;
//		}*/
//		//$获取当前帧
//		/*int curr = video.get(CAP_PROP_POS_FRAMES);
//		if (curr > fcount / 3)
//		{
//
//			printf("第%d次循环\n", count);
//			video.set(CAP_PROP_POS_FRAMES, 0);
//			count++;
//			continue;
//		}*/
//		if (frame.empty())
//		{
//			break;
//		}
//		//$获取图像的ROI区
//		r2 = frame(Rect(0, 0, cols, rows));
//		//$将r1中图像信息拷贝到ROI区中
//		r1.copyTo(r2);
//		//
//		imshow("video", frame);
//		vw.write(frame);
//		if (waitKey(s) == 27)
//			break;
//	}
//	return 0;
//}