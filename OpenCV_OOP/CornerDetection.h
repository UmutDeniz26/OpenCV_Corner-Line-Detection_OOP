#pragma once
#include "Detection.h"
class CornerDetection :
    public Detection
{
	public:
		CornerDetection(string);

		void harrisCornerDetection(int blockSize, int apertureSize, double k, int threshold, int circleTreshold = 200);
		void drawCirclesOnCorners(int treshold);

		virtual void showImage(string) const;

		~CornerDetection();
	protected:
		Mat harrisImage;
};

