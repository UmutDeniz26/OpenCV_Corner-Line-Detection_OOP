#include "CornerDetection.h"
#include <algorithm>

using namespace cv;
using namespace std;

CornerDetection::CornerDetection(string path) :Detection(path,"Corner Detection"),
	blockSize(0), apertureSize(0), threshold(0), circlethreshold(0) {}

void CornerDetection::setParameters(int blockSize, int apertureSize, int threshold, int circlethreshold) {
	bool flag;
	while (true) {
		try {
			
			flag = (blockSize <= 0) || (apertureSize <= 0) || (threshold <= 0) || (circlethreshold <= 0);
			if (flag) {throw invalid_argument("Invalid parameters! (Corner Detection)");}

			break;
		}
		catch (const invalid_argument& e) {
			cout << "Error: " << e.what() << endl;
			cout << "Enter blockSize (0-inf): "; cin >> blockSize;
			cout << "Enter apertureSize (0-inf): "; cin >> apertureSize;
			cout << "Enter threshold (0-inf): "; cin >> threshold;
			cout << "Enter circlethreshold (0-inf): "; cin >> circlethreshold;
			continue;
		}
	}
	this->blockSize = blockSize; this->apertureSize = apertureSize;
	this->threshold = threshold; this->circlethreshold = circlethreshold;
}

map<string, int> CornerDetection::getParameters(void) const {
	return { {"blockSize", blockSize}, {"apertureSize", apertureSize}, {"threshold", threshold}, {"circlethreshold", circlethreshold} };
}
void CornerDetection::harrisCornerDetection(int blockSize, int apertureSize, double k, int threshold, int circlethreshold) {
	setParameters(blockSize, apertureSize, threshold, circlethreshold);
	cornerHarris(getGrayScale(), harrisImage, blockSize, apertureSize, k);
	normalize(harrisImage, harrisImage, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
	convertScaleAbs(harrisImage, harrisImage);
	drawCirclesOnCorners(circlethreshold);
	addOutputImage("Harris Image", harrisImage);
}

void CornerDetection::drawCirclesOnCorners(int threshold) {
	for (int j = 0; j < harrisImage.rows; j++){
		for (int i = 0; i < harrisImage.cols; i++){
			if ((int)harrisImage.at<uchar>(j, i) > threshold){
				circle(harrisImage, Point(i, j), 5, Scalar(0), 2, 8, 0);
	}}}
}

void CornerDetection::printConfig(void) const {
	map <string, int> parametersConfig = getParameters();

	Detection::printConfig();	
	cout<< endl << "Parameters Config:" << endl;
	
	for_each(parametersConfig.begin(), parametersConfig.end(), [](pair<string, int> element) {
		cout << element.first << " : " << element.second << endl;
	});
}

CornerDetection::~CornerDetection() {

}



