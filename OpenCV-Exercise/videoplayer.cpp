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
//	//$���ز����õ���Ƶ
//	video.open("D:/Download/����/KDA+Offical+Music+Video.4K+Ver.webm");
//	//$�ж��Ƿ������Ƶ�ɹ�
//	if (!video.isOpened())
//	{
//		cout << "��Ƶ��ʧ��" << endl;
//		return -1;
//	}
//	Mat frame, r1, r2;
//	//$��ȡһ��ͼƬ��Ϊˮӡ
//	r1 = imread("E:/opencvpicture/train.jpg");
//	int rows, cols;
//	rows = r1.rows;
//	cols = r1.cols;
//	//$��ȡfps��������ȴ�ʱ��
//	int fps = video.get(CAP_PROP_FPS);
//	int s = 1000 / fps;
//	int time;
//	int width, height;
//	//$��ȡ��Ƶ�Ŀ�͸�
//	width = video.get(CAP_PROP_FRAME_WIDTH);
//	height = video.get(CAP_PROP_FRAME_HEIGHT);
//	//$��ȡ��Ƶ��֡��������
//	int fcount = video.get(CAP_PROP_FRAME_COUNT);
//	time = fcount / fps;
//	//
//	cout << fps << "fps" << endl;
//	cout << fcount << "֡" << endl;
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