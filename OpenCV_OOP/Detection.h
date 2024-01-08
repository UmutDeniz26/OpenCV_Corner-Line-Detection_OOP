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

		void setParametersConfig(map<string, int> parametersConfig);
		map<string, int> getParametersConfig(void) const;

		virtual void printConfig(void) const;

		~Detection();

	private:
		map<string, int> parametersConfig;

};

