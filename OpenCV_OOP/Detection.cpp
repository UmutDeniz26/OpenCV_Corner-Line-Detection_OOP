#include "Detection.h"
using namespace cv;
using namespace std;

int Detection::outCounter = 0;

Detection::Detection(string path, string title) :CommonProcess(path,title) {}

Detection::Detection(Mat image, string title) : CommonProcess(image, title) {}

void Detection::printConfig(void) const {
	CommonProcess::printConfig();
	cout << endl << "Output Images (" << outputImages.size() << "):" << endl;
	for_each(outputImages.begin(), outputImages.end(), [](pair<string, Mat> element) {
		cout << " Title: " << element.first << endl;
	});
}

void Detection::addOutputImage(string title, const Mat &image) {
	Mat clonedImage = image.clone();// this is very important, otherwise the image will be duplicated in the map
	outputImages.insert(pair<string, Mat> (title, clonedImage));
}

void Detection::showOutputImages(void) const {
	for_each(outputImages.begin(), outputImages.end(), [](pair<string, Mat> element) {
		imshow(element.first, element.second);
	});
}


int Detection::getandIncrementOutCounter(void) {
	return outCounter++;
}

Detection::~Detection() {

}