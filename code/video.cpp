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
//	video.open("D:/360�������������/cf.flv");
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
//	vw.open("E:/opencvpicture/cf.mp4", VideoWriter::fourcc('h', '2', '6', '4'),
//		fps, Size(width, height));
//	while (true)
//	{
//		//$����Ƶ���е�һ֡д�뵽mat������
//		//#����1�������������
//		video >> frame;
//		//#����2����VideoCapture�Դ�read����������д��frame��
//		/*if (!video.read(frame))
//		{
//			break;
//		}*/
//		//$��ȡ��ǰ֡
//		/*int curr = video.get(CAP_PROP_POS_FRAMES);
//		if (curr > fcount / 3)
//		{
//
//			printf("��%d��ѭ��\n", count);
//			video.set(CAP_PROP_POS_FRAMES, 0);
//			count++;
//			continue;
//		}*/
//		if (frame.empty())
//		{
//			break;
//		}
//		//$��ȡͼ���ROI��
//		r2 = frame(Rect(0, 0, cols, rows));
//		//$��r1��ͼ����Ϣ������ROI����
//		r1.copyTo(r2);
//		//
//		imshow("video", frame);
//		vw.write(frame);
//		if (waitKey(s) == 27)
//			break;
//	}
//	return 0;
//}