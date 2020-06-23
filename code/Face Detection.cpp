//#include<opencv2/opencv.hpp>
//#include<iostream>
//using namespace cv;
//using namespace std;
//int main(int argc, int** argv)
//{
//	VideoCapture capture(0);
//	Mat frame, edges;
//	CascadeClassifier detector;
//	detector.load("C:/opencv/build/etc/haarcascades/haarcascade_frontalface_alt_tree.xml");
//	vector<Rect> faces;
//
//	while (!(cvWaitKey(2) == 27))
//	{
//		capture >> frame;
//		if (frame.empty())
//		{
//			printf("--(!) No captured frame -- Break!");
//			break;
//		}
//		else
//		{
//			cvtColor(frame, edges, CV_BGR2GRAY);
//			blur(edges, edges, Size(7, 7));
//			Canny(edges, edges, 0, 30, 3);
//			imshow("src", frame);
//			imshow("Ե������Ƶ", edges);
//			detector.detectMultiScale(edges, faces, 1.1, 3, 0, Size(30, 30));
//
//			for (size_t t = 0; t < faces.size(); t++)
//			{
//				rectangle(frame, faces[t], Scalar(0, 0, 225), 2, 8);
//				imshow("face detector", frame);
//			}
//		}
//	}
//
//	return 0;
//}






/*!
* \file Capture.cpp
*
* \author ranjiewen
* \date ʮһ�� 2016
*
*  http://www.cnblogs.com/tanfy/p/5552270.html

����opencv�Դ�����ʶ��Դ�루����/opencv-3.1.0/samples/cpp/facedetect.cpp��
*/

//#include<opencv2/opencv.hpp>
//#include <iostream>
//
//using namespace std;
//using namespace cv;
//
//static void help()
//{
//	cout << "\nThis program demonstrates the cascade recognizer. Now you can use Haar or LBP features.\n"
//		"This classifier can recognize many kinds of rigid objects, once the appropriate classifier is trained.\n"
//		"It's most known use is for faces.\n"
//		"Usage:\n"
//		"./facedetect [--cascade=<cascade_path> this is the primary trained classifier such as frontal face]\n"
//		"   [--nested-cascade[=nested_cascade_path this an optional secondary classifier such as eyes]]\n"
//		"   [--scale=<image scale greater or equal to 1, try 1.3 for example>]\n"
//		"   [--try-flip]\n"
//		"   [filename|camera_index]\n\n"
//		"see facedetect.cmd for one call:\n"
//		"./facedetect --cascade=\"../../data/haarcascades/haarcascade_frontalface_alt.xml\" --nested-cascade=\"../../data/haarcascades/haarcascade_eye_tree_eyeglasses.xml\" --scale=1.3\n\n"
//		"During execution:\n\tHit any key to quit.\n"
//		"\tUsing OpenCV version " << CV_VERSION << "\n" << endl;
//}
//
//void detectAndDraw(Mat& img, CascadeClassifier& cascade,
//	CascadeClassifier& nestedCascade,
//	double scale, bool tryflip);
//
//string cascadeName;
//string nestedCascadeName;
//
//
//
//int main(int argc, const char** argv)
//{
//	VideoCapture capture;
//	Mat frame, image;
//	string inputName;
//	bool tryflip;
//
//	// CascadeClassifier��Opencv������������ʱ���һ������������������������ѡ��һ��ʹ���ϰ汾��CvHaarClassifierCascade������һ��ʹ���°汾��CascadeClassifier�ࡣ�ϰ汾�ķ�����ֻ֧����Haar���������°汾�ķ������ȿ���ʹ��Haar��Ҳ����ʹ��LBP������
//	CascadeClassifier cascade, nestedCascade;
//	double scale;
//
//	CommandLineParser parser(argc, argv,
//		"{help h||}"
//		"{cascade|c:/opencv/sources/data/haarcascades/haarcascade_frontalface_alt.xml|}"   //Ĭ��·��ʵ�ڰ�װ·����sample���޸���·�����Ա����load�ɹ�
//		"{nested-cascade|c:/opencv/sources/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml|}"  //�޸�·��
//		"{scale|1|}{try-flip||}{@filename||}" //�ļ�Ϊ��ʱ����������ͷ��ʵʱ�������
//	);
//	if (parser.has("help"))
//	{
//		help();
//		return 0;
//	}
//
//	cascadeName = parser.get<string>("cascade");
//	nestedCascadeName = parser.get<string>("nested-cascade");
//	scale = parser.get<double>("scale");
//	if (scale < 1)
//		scale = 1;
//	tryflip = parser.has("try-flip");
//	inputName = parser.get<string>("@filename");
//	std::cout << inputName << std::endl;  // test
//	if (!parser.check())
//	{
//		parser.printErrors();
//		return 0;
//	}
//
//	// ����ģ��
//	if (!nestedCascade.load(nestedCascadeName))
//		cerr << "WARNING: Could not load classifier cascade for nested objects" << endl;
//	if (!cascade.load(cascadeName))
//	{
//		cerr << "ERROR: Could not load classifier cascade" << endl;
//		help();
//		return -1;
//	}
//	// ��ȡ����ͷ
//	// isdigit����ַ��Ƿ�Ϊ���������� 
//	if (inputName.empty() || (isdigit(inputName[0]) && inputName.size() == 1))
//	{
//		int c = inputName.empty() ? 0 : inputName[0] - '0';
//		// �˴���ϵͳ��������ϣ���������������ýӹ�����ͷ�������(M)-> ���ƶ��豸 -> ����ͷ���� -> ����(�Ͽ�����������)
//		if (!capture.open(c))
//			cout << "Capture from camera #" << c << " didn't work" << endl;
//		else {
//			capture.set(CV_CAP_PROP_FRAME_WIDTH, 640);
//			capture.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
//		}
//	}
//	else if (inputName.size())
//	{
//		image = imread(inputName, 1);
//		if (image.empty())
//		{
//			if (!capture.open(inputName))
//				cout << "Could not read " << inputName << endl;
//		}
//	}
//	else
//	{
//		image = imread("../data/lena.jpg", 1);
//		if (image.empty()) cout << "Couldn't read ../data/lena.jpg" << endl;
//	}
//
//	if (capture.isOpened())
//	{
//		cout << "Video capturing has been started ..." << endl;
//
//
//		for (;;)
//		{
//			std::cout << "capturing..." << std::endl;  // test
//			capture >> frame;
//			if (frame.empty())
//				break;
//
//			Mat frame1 = frame.clone();
//			std::cout << "Start to detect..." << std::endl;  // test
//			detectAndDraw(frame1, cascade, nestedCascade, scale, tryflip);
//
//			int c = waitKey(10);
//			if (c == 27 || c == 'q' || c == 'Q')
//				break;
//		}
//	}
//	else
//	{
//		cout << "Detecting face(s) in " << inputName << endl;
//		if (!image.empty())
//		{
//			detectAndDraw(image, cascade, nestedCascade, scale, tryflip);
//			waitKey(0);
//		}
//		else if (!inputName.empty())
//		{
//			/* assume it is a text file containing the
//			list of the image filenames to be processed - one per line */
//			FILE* f;
//				/*= fopen(inputName.c_str(), "rt");*/
//				fopen_s(&f, inputName.c_str(), "rt");
//			if (f)
//			{
//				char buf[1000 + 1];
//				while (fgets(buf, 1000, f))
//				{
//					int len = (int)strlen(buf), c;
//					while (len > 0 && isspace(buf[len - 1]))
//						len--;
//					buf[len] = '\0';
//					cout << "file " << buf << endl;
//					image = imread(buf, 1);
//					if (!image.empty())
//					{
//						detectAndDraw(image, cascade, nestedCascade, scale, tryflip);
//						c = waitKey(0);
//						if (c == 27 || c == 'q' || c == 'Q')
//							break;
//					}
//					else
//					{
//						cerr << "Aw snap, couldn't read image " << buf << endl;
//					}
//				}
//				fclose(f);
//			}
//		}
//	}
//
//	return 0;
//}
//
//void detectAndDraw(Mat& img, CascadeClassifier& cascade,
//	CascadeClassifier& nestedCascade,
//	double scale, bool tryflip)
//{
//	double t = 0;
//	vector<Rect> faces, faces2;
//	const static Scalar colors[] =
//	{
//		Scalar(255, 0, 0),
//		Scalar(255, 128, 0),
//		Scalar(255, 255, 0),
//		Scalar(0, 255, 0),
//		Scalar(0, 128, 255),
//		Scalar(0, 255, 255),
//		Scalar(0, 0, 255),
//		Scalar(255, 0, 255)
//	};
//	Mat gray, smallImg;
//
//	cvtColor(img, gray, COLOR_BGR2GRAY);
//	double fx = 1 / scale;
//	resize(gray, smallImg, Size(), fx, fx, INTER_LINEAR);
//	equalizeHist(smallImg, smallImg);
//
//	t = (double)cvGetTickCount();
//	cascade.detectMultiScale(smallImg, faces,
//		1.1, 2, 0
//		//|CASCADE_FIND_BIGGEST_OBJECT
//		//|CASCADE_DO_ROUGH_SEARCH
//		| CASCADE_SCALE_IMAGE,
//		Size(30, 30));
//	if (tryflip)
//	{
//		flip(smallImg, smallImg, 1);
//		cascade.detectMultiScale(smallImg, faces2,
//			1.1, 2, 0
//			//|CASCADE_FIND_BIGGEST_OBJECT
//			//|CASCADE_DO_ROUGH_SEARCH
//			| CASCADE_SCALE_IMAGE,
//			Size(30, 30));
//		for (vector<Rect>::const_iterator r = faces2.begin(); r != faces2.end(); r++)
//		{
//			faces.push_back(Rect(smallImg.cols - r->x - r->width, r->y, r->width, r->height));
//		}
//	}
//	t = (double)cvGetTickCount() - t;
//	printf("detection time = %g ms\n", t / ((double)cvGetTickFrequency()*1000.));
//	for (size_t i = 0; i < faces.size(); i++)
//	{
//		Rect r = faces[i];
//		Mat smallImgROI;
//		vector<Rect> nestedObjects;
//		Point center;
//		Scalar color = colors[i % 8];
//		int radius;
//
//		double aspect_ratio = (double)r.width / r.height;
//		if (0.75 < aspect_ratio && aspect_ratio < 1.3)
//		{
//			center.x = cvRound((r.x + r.width*0.5)*scale);
//			center.y = cvRound((r.y + r.height*0.5)*scale);
//			radius = cvRound((r.width + r.height)*0.25*scale);
//			circle(img, center, radius, color, 3, 8, 0);
//		}
//		else
//			rectangle(img, cvPoint(cvRound(r.x*scale), cvRound(r.y*scale)),
//				cvPoint(cvRound((r.x + r.width - 1)*scale), cvRound((r.y + r.height - 1)*scale)),
//				color, 3, 8, 0);
//		if (nestedCascade.empty())
//			continue;
//		smallImgROI = smallImg(r);
//		nestedCascade.detectMultiScale(smallImgROI, nestedObjects,
//			1.1, 2, 0
//			//|CASCADE_FIND_BIGGEST_OBJECT
//			//|CASCADE_DO_ROUGH_SEARCH
//			//|CASCADE_DO_CANNY_PRUNING
//			| CASCADE_SCALE_IMAGE,
//			Size(30, 30));
//		for (size_t j = 0; j < nestedObjects.size(); j++)
//		{
//			Rect nr = nestedObjects[j];
//			center.x = cvRound((r.x + nr.x + nr.width*0.5)*scale);
//			center.y = cvRound((r.y + nr.y + nr.height*0.5)*scale);
//			radius = cvRound((nr.width + nr.height)*0.25*scale);
//			circle(img, center, radius, color, 3, 8, 0);
//		}
//	}
//	imshow("result", img);
//}





//#include <opencv.hpp>
//#include <opencv2/core/core.hpp>
//#include <iostream>
//
//using namespace cv;
//
//void Pic2Gray(Mat camerFrame, Mat &gray)
//{
//	//��̨ͨʽ��3ͨ��BGR,�ƶ��豸Ϊ4ͨ��
//	if (camerFrame.channels() == 3)
//	{
//		cvtColor(camerFrame, gray, CV_BGR2GRAY);
//	}
//	else if (camerFrame.channels() == 4)
//	{
//		cvtColor(camerFrame, gray, CV_BGRA2GRAY);
//	}
//	else
//		gray = camerFrame;
//}
//
//
//int main()
//{
//	//����Haar��LBP��������������
//	CascadeClassifier faceDetector;
//	std::string faceCascadeFilename = "C:/opencv/build/etc/haarcascades/haarcascade_frontalface_default.xml";
//
//	//�Ѻô�����Ϣ��ʾ
//	try {
//		faceDetector.load(faceCascadeFilename);
//	}
//	catch (Exception e) {}
//	if (faceDetector.empty())
//	{
//		std::cerr << "������������ܼ��� (";
//		std::cerr << faceCascadeFilename << ")!" << std::endl;
//		exit(1);
//	}
//
//	//������ͷ
//	VideoCapture camera(0);
//	while (true)
//	{
//		Mat camerFrame;
//		camera >> camerFrame;
//		if (camerFrame.empty())
//		{
//			std::cerr << "�޷���ȡ����ͷͼ��" << std::endl;
//			getchar();
//			exit(1);
//		}
//		Mat displayedFrame(camerFrame.size(), CV_8UC3);
//
//
//		//�������ֻ�����ڻҶ�ͼ��
//		Mat gray;
//		Pic2Gray(camerFrame, gray);
//
//
//
//		//ֱ��ͼ���Ȼ�(����ͼ��ĶԱȶȺ�����)
//		Mat equalizedImg;
//		equalizeHist(gray, equalizedImg);
//
//		//���������Cascade Classifier::detectMultiScale�������������
//
//		int flags = CASCADE_FIND_BIGGEST_OBJECT | CASCADE_DO_ROUGH_SEARCH;	//ֻ�����������
//																			//int flags = CASCADE_SCALE_IMAGE;	//�������
//		Size minFeatureSize(30, 30);
//		float searchScaleFactor = 1.1f;
//		int minNeighbors = 4;
//		std::vector<Rect> faces;
//		faceDetector.detectMultiScale(equalizedImg, faces, searchScaleFactor, minNeighbors, flags, minFeatureSize);
//
//		//�����ο�
//		cv::Mat face;
//		cv::Point text_lb;
//		for (size_t i = 0; i < faces.size(); i++)
//		{
//			if (faces[i].height > 0 && faces[i].width > 0)
//			{
//				face = gray(faces[i]);
//				text_lb = Point(faces[i].x, faces[i].y);
//				rectangle(equalizedImg, faces[i], cv::Scalar(0, 0, 255), 1, 8, 0);
//				rectangle(gray, faces[i], cv::Scalar(0, 0, 255), 1, 8, 0);
//				rectangle(camerFrame, faces[i], cv::Scalar(0, 0, 255), 1, 8, 0);
//			}
//		}
//
//
//		imshow("ֱ��ͼ���Ȼ�", equalizedImg);
//		imshow("�ҶȻ�", gray);
//		imshow("ԭͼ", camerFrame);
//
//		waitKey(20);
//	}
//
//	getchar();
//	return 0;
//}
