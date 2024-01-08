#pragma once
#include "CommonProcess.h"
#include <iostream>
#include <string>

class Detection :
    public CommonProcess
{
    public:
		Detection(string,string="untitled");
		Detection(Mat,string="untitled");

		virtual void printConfig(void) const;
		
		static int getandIncrementOutCounter(void);

		void addOutputImage(string, Mat);
		void showOutputImages(void) const;

		~Detection();

	private:
		static int outCounter;
		map <string, Mat> outputImages;
};

