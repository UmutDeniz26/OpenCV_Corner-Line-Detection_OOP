#include "LineDetection.h"
using namespace cv;
using namespace std;

LineDetection::LineDetection(string path) :Detection(path, "Line Detection"),
	treshold1(0), treshold2(0), apertureSize(0) {} 

void LineDetection::setParameters(int treshold1, int treshold2, int apertureSize) {
	while (bool flag = true) {
		try {
			flag = (treshold1 <= 0 || treshold1>255) || (treshold2 <= 0 || treshold2>255) || (apertureSize <= 0);
			if (flag) {
				throw invalid_argument("Invalid parameters!");
			}
			break;
		}
		catch (const invalid_argument& e) {
			cout << "Error: " << e.what() << " (LineDetection)" << endl;
			cout << "Enter treshold1 (0-255): "; cin >> treshold1;
			cout << "Enter treshold2 (0-255): "; cin >> treshold2;
			cout << "Enter apertureSize (0-inf): "; cin >> apertureSize;
			continue;
		}
    }
    this->treshold1 = treshold1; this->treshold2 = treshold2; this->apertureSize = apertureSize;
}

map<string, int> LineDetection::getParameters(void) const {
	return { {"treshold1", treshold1}, {"treshold2", treshold2}, {"apertureSize", apertureSize} };
}

void LineDetection::cannyDetection(int treshold1, int treshold2, int apertureSize) {
	setParameters(treshold1, treshold2, apertureSize);
	Canny(getGrayScale(), cannyImage, 50, 200, 3);
	addOutputImage("Canny Image", cannyImage);
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