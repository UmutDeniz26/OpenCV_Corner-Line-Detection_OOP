#include "CornerDetection.h"

using namespace cv;
using namespace std;

CornerDetection::CornerDetection(string path) :Detection(path,"Corner Detect") {

}

void CornerDetection::harrisCornerDetection(int blockSize, int apertureSize, double k, int threshold, int circleTreshold) {
	cornerHarris(getGrayScale(), harrisImage, blockSize, apertureSize, k);
	normalize(harrisImage, harrisImage, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
	convertScaleAbs(harrisImage, harrisImage);
	drawCirclesOnCorners(circleTreshold);

}
void CornerDetection::drawCirclesOnCorners(int treshold) {
	for (int j = 0; j < harrisImage.rows; j++){
		for (int i = 0; i < harrisImage.cols; i++){
			if ((int)harrisImage.at<uchar>(j, i) > treshold){
				circle(harrisImage, Point(i, j), 5, Scalar(0), 2, 8, 0);
			}
		}
	}
}

void CornerDetection::showImage(string) const {
		imshow("Harris Corner Detection", harrisImage);
}


CornerDetection::~CornerDetection() {

}



