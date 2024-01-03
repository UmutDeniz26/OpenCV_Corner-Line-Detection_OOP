#include "CommonProcess.h"
using namespace cv;
using namespace std;

CommonProcess::CommonProcess(string path, string titleIn):title(titleIn)
{
	loadRawRGBImage(path);
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

Mat CommonProcess::getRawRGBImage()const {
	return rawRGBImage;
}
Size CommonProcess::getSize()const {
	return size;
}
string CommonProcess::getTitle()const {
	return title;
}

void CommonProcess::setTitle(string titleIn) {
	title = titleIn;
}
void CommonProcess::setSize(Size sizeIn) {
	size = sizeIn;
}
void CommonProcess::setRawRGBImage(Mat image) {
	rawRGBImage = image;
}

void CommonProcess::loadRawRGBImage(string path) {
	rawRGBImage = imread(path);
}

void CommonProcess::showImage(string windowName) const {
	imshow(windowName, rawRGBImage);
}

void CommonProcess::printConfig() const {
	//system("cls");
	cout << "Title: " << title << endl;
	cout << "Image size: " << size << endl;

}

CommonProcess::~CommonProcess()
{

}