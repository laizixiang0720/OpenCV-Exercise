//��Mat����Ĳ���
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

//rgbͼת�Ҷ�ͼ
void im2gray(Mat& src, Mat& dst) {
	uchar r, b, g, color;
	dst.create(src.size(), CV_8UC1);
	/*blur(src, src, Size(3, 3));*/
	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++)
		{
			b = src.ptr<uchar>(i, j)[0];
			g = src.ptr<uchar>(i, j)[1];
			r = src.ptr<uchar>(i, j)[2];
			color = (r * 229 + g * 587 + b * 114 + 500) / 1000;
			dst.ptr<uchar>(i, j)[0] = color;
		}
}

//����ͼ�����ȺͶԱȶȵĺ���
void changeGain(Mat &src, Mat &dst, float a, int b)
{

	dst.create(src.size(), src.type());
	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j = j++)
		{
			for (int c = 0; c < 3; c++)
				(&dst.data[i*dst.step + j * dst.channels()])[c] = saturate_cast<uchar>(a * (src.at<Vec3b>(i, j)[c]) + b);
		}
	}
}

//�Ҷ�ͼ��ֵ������
//thresh��ֵ��maxval���ֵ
void im2bw(Mat &src, Mat &dst, double thresh, double maxval)
{
	uchar *rank;
	dst.create(src.size(), src.type());
	for (int i = 0; i < src.rows; i++)
	{
		rank = src.ptr<uchar>(i);
		for (int j = 0; j < src.cols; j++)
		{
			if (rank[j] > thresh)
			{
				dst.at<uchar>(i, j) = maxval;
			}
			else
			{
				dst.at<uchar>(i, j) = 0;
			}
		}
	}
}

//�����㷨��ʵ��
void Csize(Mat &src, Mat &dst, Size size)
{
	dst.create(size, src.type());
	int sy, sx = 0;//ӳ��ԭͼλ��
	float fy, fx;
	//����ԭͼ������֮��ı���
	fy = (float)src.rows / dst.rows;
	fx = (float)src.cols / dst.cols;
	//��������֮���ͼ���ҵ���ԭͼ����Ӧ��λ��
	for (int y = 0; y < dst.rows; y++)
	{
		sy = fy * y;
		for (int x = 0; x < dst.cols; x++)
		{
			sx = fx * x;
			dst.at<Vec3b>(y, x) = src.at<Vec3b>(sy, sx);
		}
	}
}


int main()
{
	//����ͼƬ
	Mat src = imread("e:/opencvpicture/nophoto.png");
	Mat dst, gray1, gray2, bin1, bin2, gain, gain1, roi, lsrc, gsrc,ysrc;
	Mat dst1, dst2;
	uchar color, r, g, b;
	uchar *rank;
	Size size(50, 50);
	Point point(100, 100);
	Rect rect(0, 0, 200, 200);
	int cols;
	int rows;
	if (src.empty())
	{
		cout << "�޷�����ͼ������ͼ��·����" << endl;
		return -1;
	}
	//opencv�ṩ�Ľӿڽ�rgbͼת��Ϊ�Ҷ�ͼ
	cvtColor(src, gray1, CV_RGB2GRAY);
	//���Ա�д�ĺ�����rgbͼת��Ϊ�Ҷ�ͼ
	im2gray(src, gray2);
	//opencv�Դ���ת���������Ҷ�ͼ��ֵ��
	threshold(gray1, bin1, 100, 225, THRESH_BINARY);
	//�Լ���д�Ķ�ֵ������
	im2bw(gray2, bin2, 100, 225);
	//�Լ���д��ͼ�����ȺͶԱȶȵĺ���
	changeGain(src, gain, 2.0, 50);
	//opencv�Դ��ĶԱȶȺ����ȵ�������
	src.convertTo(gain1, -1, 2.0, 50);
	//
	resize(src, dst1, size, 0, 0);
	//
	Csize(src, dst2, Size(640, 960));
	pyrDown(src, gsrc);
	pyrUp(src, lsrc);
	pyrDown(lsrc,ysrc);
	roi = src(rect);
	//
	rank = gray1.ptr<uchar>(0);
	rows = gray1.rows;
	cols = gray1.cols;
	cout << gray1.step << endl;
	cout << gray1.cols << endl;
	for (int col = 0; col < cols; col++)
		printf("��1�е���%d:%d\n", col + 1, rank[col]);
	//ͼ����ʾ
	imshow("src", src);
	imshow("roi", roi);
	imshow("CV_RGB2GRAY", gray1);
	imshow("im2gray1", gray2);
	imshow("threshold", bin1);
	imshow("im2bw1", bin2);
	imshow("changeGain", gain);
	imshow("convertTo", gain1);
	imshow("csize", dst1);
	imshow("csize1", dst2);
	imshow("gsrc", gsrc);
	imshow("lsrc", lsrc);
	imshow("ysrc", ysrc);
	imwrite("E:/nophoto.png", dst1);
	waitKey(0);
	return 0;
}