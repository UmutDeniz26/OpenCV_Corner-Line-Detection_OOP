#pragma once

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

class CommonProcess
{
	public:
		CommonProcess(string,string);
		CommonProcess(Mat,string);
		
		void loadRawRGBImage(string);
		void setRawRGBImage(Mat);
		void setSize(Size);
		void setTitle(string);
		void setFilePath(string);

		string getFilePath(void) const;
		string getTitle(void) const;
		Size getSize(void) const;
		Mat getGrayScale(void) const;
		Mat getRawRGBImage(void)const;
		Mat getResizedImage(Size) const;

		virtual void printConfig(void) const;
		virtual void showImage(string) const;

		~CommonProcess();
	private:
		string title,filePath;
		Size size;
		Mat rawRGBImage;

};

