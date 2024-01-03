#include "LineDetection.h"
using namespace cv;
using namespace std;

LineDetection::LineDetection(string path) :Detection(path) {

}

void LineDetection::cannyDetection(int treshold1, int treshold2, int apertureSize) {
	/*
	Parameters:
	1. Input image: 8-bit input image.
	2. Output image: 8-bit output image.
	3. Threshold 1: The value of threshold1 is used for edge linking and threshold2 is used to find the initial segments of strong edges.
	4. Threshold 2: The value of threshold1 is used for edge linking and threshold2 is used to find the initial segments of strong edges.
	5. Aperture size: The aperture size is the size of Sobel kernel used for find image gradients.
	*/
	Canny(getGrayScale(), cannyImage, 50, 200, 3);
}

void LineDetection::showImage(string windowName) const
{
	imshow(windowName, cannyImage);
}

LineDetection::~LineDetection() {

}