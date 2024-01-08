#pragma once
#include "Detection.h"
class CornerDetection :
    public Detection
{
	public:
		/// Constructor
		CornerDetection(string);

		/// This function detects corners using Harris Corner Detection algorithm
		void harrisCornerDetection(int blockSize, int apertureSize, double k, int circlethreshold);

		/// This function draws circles on corners due to the threshold
		void drawCirclesOnCorners(int threshold);

		/// Setter Getters
		void setParameters(int,int,double,int);
		map<string, double> getParameters(void) const;

		/// This function prints the configuration of the object
		void printConfig(void) const;

		/// Destructor
		~CornerDetection();
	private:
		int blockSize, apertureSize, circlethreshold;	/* parameters of the algorithm */
		double k;
		Mat harrisImage;											/* output image */

};

