#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/core/utils/logger.hpp>

#include "CommonProcess.h"
#include "Detection.h"
#include "LineDetection.h"
#include "CornerDetection.h"

using namespace std;
using namespace cv;


int main()
{
	//Hide opencv [INFO]
	setLogLevel(utils::logging::LOG_LEVEL_SILENT);

	LineDetection ld("lena.jpeg");
	ld.cannyDetection(50, 200, 5);
	ld.showImage("Canny Image");
	ld.showOutputImages();

	CornerDetection cd("house.jpeg");
	cd.setRawRGBImage(cd.getResizedImage(Size(512, 512)));
	cd.harrisCornerDetection(2, 3, 0.04, 100);
	cd.showImage("Harris Corner Detection");
	cd.showOutputImages();

	cd.printConfig(); 
	ld.printConfig();

	waitKey(0);
	destroyAllWindows();

	return 0;


}