
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

vector<vector<Point>> contours;
vector<vector<Point>> polycontours;
vector<Vec4i> hierarchy;



int main() {

	img = imread("test01.jpg", 1);
	cout << type(img) << endl;
	//convert to gray
	cvtColor(img, grayimg, CV_RGB2GRAY);
	//THr
	threshold(grayimg, grayimg, 186, 255, THRESH_BINARY);

	//blur(grayimg, grayimg, Size(5, 5));
	//
	//Canny(grayimg, grayimg, 100, 300, 3);
	//find contours
	findContours(grayimg, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

	//approxPolyDP(contours, polycontours, 4, 1);

	/*
		for (int i = 0; i < contours.size(); i++) {
		if (hierarchy[i][2] > 10) {
			drawContours(img, contours, i, Scalar(0,255,0), 2, 8, hierarchy, 0, Point());
		}
	
	}
	
	
	*/

	

	namedWindow("img", WINDOW_AUTOSIZE);
	//createTrackbar("Threshold:", "img", &value, 500, thr);
	//createTrackbar("MaxValue:", "img", &maxvalue, 500, thr);
	imshow("img", img);
	waitKey(0);


}


void thr(int, void*) {
	 //186
	//adaptiveThreshold(grayimg, thrimg, maxvalue, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 5, 2);
	//Canny(grayimg, thrimg, value, 300, 3);
	imshow("img", thrimg);
}