#include "Detection.h"
using namespace cv;
using namespace std;

int Detection::outCounter = 0;

Detection::Detection(string path, string title) :CommonProcess(path,title) {}

void Detection::printConfig(void) const {
	CommonProcess::printConfig();
	cout << endl << "Output Images (" << outputImages.size() << "):" << endl;
	for_each(outputImages.begin(), outputImages.end(), [](pair<string, Mat> element) {
		cout << " Title: " << element.first << endl;
	});
}

void Detection::addOutputImage(string title, Mat image) {
	imshow(title+ " in func ", image);
	outputImages.insert(pair<string, Mat>(title, image));
}

void Detection::showOutputImages(void) const {
	auto it = outputImages.begin();
	for_each(outputImages.begin(), outputImages.end(), [](pair<string, Mat> element) {
		imshow(element.first, element.second);
		cout << " Title: " << element.first << endl;
		cout << " Average magnitude of Image last row : " << mean(element.second.row(element.second.rows - 1)) << endl;
	});

}

int Detection::getandIncrementOutCounter(void) {
	return outCounter++;
}

Detection::Detection(Mat image, string title) : CommonProcess(image, title) {

}

Detection::~Detection() {

}