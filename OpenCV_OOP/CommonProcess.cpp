#include "CommonProcess.h"
using namespace cv;
using namespace std;

CommonProcess::CommonProcess(string path, string titleIn):title(titleIn),filePath(path)
{
	loadRawRGBImage(path);
}
CommonProcess::CommonProcess(Mat image, string titleIn) :title(titleIn), rawRGBImage(image), filePath("")
{
	size = rawRGBImage.size();
}

Mat CommonProcess::getGrayScale()const {
	Mat grayScaleImage;
	cvtColor(rawRGBImage, grayScaleImage, COLOR_BGR2GRAY);
	return grayScaleImage;
}
Mat CommonProcess::getResizedImage(Size size)const {
	Mat resizedImage;
	resize(rawRGBImage, resizedImage, size);
	return resizedImage;
}

string CommonProcess::getFilePath()const {return filePath;}
Mat CommonProcess::getRawRGBImage()const {return rawRGBImage;}
Size CommonProcess::getSize()const {return size;}
string CommonProcess::getTitle()const {return title;}

void CommonProcess::setFilePath(string path) { filePath = path; }
void CommonProcess::setTitle(string titleIn) {title = titleIn;}
void CommonProcess::setSize(Size sizeIn) {size = sizeIn;}

void CommonProcess::setRawRGBImage(Mat image) {
	setSize(image.size());
	rawRGBImage = image;
}

void CommonProcess::loadRawRGBImage(string path) {
	try {
		rawRGBImage = imread(path);
		setSize(rawRGBImage.size());
	}
	catch (invalid_argument &e) {
		cout << "Error: " << e.what() << endl;
	}	
}

void CommonProcess::showImage(string windowName) const {
	imshow(windowName, rawRGBImage);
}

void CommonProcess::printConfig() const {
	//system("cls");
	cout <<endl << endl << endl <<"Title: " << title << endl;
	cout << "Image size: " << size << endl;

}

CommonProcess::~CommonProcess()
{

}