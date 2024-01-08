#include "LineDetection.h"
using namespace cv;
using namespace std;

LineDetection::LineDetection(string path) :Detection(path, "Line Detection"),
	threshold1(0), threshold2(0), apertureSize(0) {} 

void LineDetection::setParameters(int threshold1, int threshold2, int apertureSize) {
	bool flag;
	while (true) {
		try {
			flag = (threshold1 <= 0 || threshold1>255) || (threshold2 <= 0 || threshold2>255) || (apertureSize <= 0);
			if (flag) {throw invalid_argument("Invalid parameters! (Line Detection)");}

			break;
		}
		catch (const invalid_argument& e) {
			cout << "Error: " << e.what() << endl;
			cout << "Enter threshold1 (0-255): "; cin >> threshold1;
			cout << "Enter threshold2 (0-255): "; cin >> threshold2;
			cout << "Enter apertureSize (0-inf): "; cin >> apertureSize;
			continue;
		}
    }
    this->threshold1 = threshold1; this->threshold2 = threshold2; this->apertureSize = apertureSize;
}

map<string, int> LineDetection::getParameters(void) const {
	return { {"threshold1", threshold1}, {"threshold2", threshold2}, {"apertureSize", apertureSize} };
}

void LineDetection::cannyDetection(int threshold1, int threshold2, int apertureSize) {
	setParameters(threshold1, threshold2, apertureSize);
	//imshow("in func GrayScale Image " + to_string(Detection::getandIncrementOutCounter()), getGrayScale());
	

	cout << "Canny Image: " << getRawRGBImage().flags << endl;
	Canny(getGrayScale(), cannyImage, 50, 200, 3);

	addOutputImage("Canny Image " + to_string(Detection::getandIncrementOutCounter()), cannyImage);

}


void LineDetection::printConfig(void) const {
	Detection::printConfig();

	cout << endl << "Parameters Config:" << endl;
	map <string, int> parametersConfig = getParameters();
	map <string, int> ::iterator itr;

	for_each(parametersConfig.begin(), parametersConfig.end(), [](pair<string, int> element) {
		cout << element.first << " : " << element.second << endl;
	});
}

LineDetection::~LineDetection() {

}