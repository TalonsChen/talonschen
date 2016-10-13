
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;


int value;
int maxvalue;
void thr(int, void*);
Mat img;
Mat grayimg;
Mat thrimg;

int main() {

	img = imread("test01.jpg", 1);
	//convert to gray
	cvtColor(img, grayimg, CV_RGB2GRAY);
	//THr
	threshold(grayimg, grayimg, 186, 255, THRESH_BINARY);

	

	namedWindow("img", WINDOW_AUTOSIZE);
	//createTrackbar("Threshold:", "img", &value, 255, thr);
	//createTrackbar("MaxValue:", "img", &maxvalue, 255, thr);
	imshow("img", grayimg);
	waitKey(0);


}


void thr(int, void*) {
	 //186
	//adaptiveThreshold(grayimg, thrimg, maxvalue, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 5, 2);
	imshow("img", thrimg);
}