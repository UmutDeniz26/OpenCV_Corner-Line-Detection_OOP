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
	//Hide opencv [INFO] 0x0000024cb4ede080 -> house
	setLogLevel(utils::logging::LOG_LEVEL_SILENT);

	LineDetection ld("house.jpeg");
	ld.setRawRGBImage(ld.getResizedImage(Size(512, 512)));
	ld.cannyDetection(50, 150, 3);


	ld.loadRawRGBImage("lena.jpeg");
	ld.cannyDetection(50, 150, 3);

	ld.showOutputImages();

	CornerDetection cd("house.jpeg");
	cd.setRawRGBImage( cd.getResizedImage(Size(512, 512)) );
	cd.harrisCornerDetection(2, 3, 0.04, 100,108);
	
	cd.loadRawRGBImage("lena.jpeg");
	cd.harrisCornerDetection(2, 3, 0.04, 100, 130);


	cd.showOutputImages();

	cd.printConfig(); 
	ld.printConfig();

	waitKey(0);
	destroyAllWindows();

	return 0;


}