#include "LineDetection.h"
using namespace cv;
using namespace std;

LineDetection::LineDetection(string path) :Detection(path,"Line Detection") {

}

void LineDetection::cannyDetection(int treshold1, int treshold2, int apertureSize) {
	
	setParametersConfig({ {"treshold1", treshold1}, {"treshold2", treshold2}, {"apertureSize", apertureSize} });
	Canny(getGrayScale(), cannyImage, 50, 200, 3);
}

void LineDetection::showImage(string windowName) const
{
	imshow(windowName, cannyImage);
}

void LineDetection::printConfig(void) const {
	CommonProcess::printConfig();
	Detection::printConfig();
}

LineDetection::~LineDetection() {

}