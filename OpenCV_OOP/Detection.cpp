#include "Detection.h"
using namespace cv;
using namespace std;

Detection::Detection(string path, string title) :CommonProcess(path,title) {}

void Detection::setParametersConfig(map<string, int> parametersConfigIn) {
	parametersConfig = parametersConfigIn;
}
map<string, int> Detection::getParametersConfig(void) const {
	return parametersConfig;
}

void Detection::printConfig(void) const {
	map<string, int> ::iterator itr;
	
	cout << endl<<"Parameters Config:" << endl;
	std::for_each(parametersConfig.begin(), parametersConfig.end(), [](std::pair<std::string, int> element) {
		cout << element.first << " : " << element.second << endl;
	});
}


Detection::Detection(Mat image, string title) : CommonProcess(image, title) {

}

Detection::~Detection() {

}