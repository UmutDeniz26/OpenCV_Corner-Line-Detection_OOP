#pragma once
#include "Detection.h"
class CornerDetection :
    public Detection
{
	public:
		CornerDetection(string);

		/*
		Parameters:
			blockSize – Neighborhood size
			apertureSize – Aperture parameter for the Sobel() operator
			k – Harris detector free parameter
			threshold – Threshold for the Harris cornerness response
			circlethreshold - Threshold for the circle detection
		*/

		void harrisCornerDetection(int blockSize, int apertureSize, double k, int threshold, int circlethreshold = 200);
		void drawCirclesOnCorners(int threshold);

		void setParameters(int,int,int,int);
		map<string, int> getParameters(void) const;

		void printConfig(void) const;

		~CornerDetection();
	private:
		int blockSize, apertureSize, threshold, circlethreshold;
		Mat harrisImage;

};

