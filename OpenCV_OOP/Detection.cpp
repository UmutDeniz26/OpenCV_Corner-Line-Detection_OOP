#include "Detection.h"
using namespace cv;
using namespace std;

Detection::Detection(string path, string title) :CommonProcess(path,title) {}

void Detection::printConfig(void) const {
	CommonProcess::printConfig();
	cout << endl << "Output Images (" << outputImages.size() << "):" << endl;
	for_each(outputImages.begin(), outputImages.end(), [](pair<string, Mat> element) {
		cout << " Title: " << element.first << endl;
	});
}

void Detection::addOutputImage(string title, Mat image) {
	outputImages.insert(pair<string, Mat>(title, image));
}

void Detection::showOutputImages(void) const {
	for_each(outputImages.begin(), outputImages.end(), [this](pair<string, Mat> element) {
		imshow(element.first, element.second);
	});
}

Detection::Detection(Mat image, string title) : CommonProcess(image, title) {

}

Detection::~Detection() {

}