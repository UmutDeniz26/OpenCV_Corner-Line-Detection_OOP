/**
 * @file CornerDetection.cpp
 * @brief Implementation of the CornerDetection class for corner detection in images.
 */

#include "CornerDetection.h"
#include <algorithm>

using namespace cv;
using namespace std;

/**
 * @brief Constructor for the CornerDetection class.
 * @param path The path to the image for corner detection.
 */
CornerDetection::CornerDetection(string path) : Detection(path, "Corner Detection"),
blockSize(0), apertureSize(0), k(0), circlethreshold(0) {}

/**
 * @brief Sets the parameters for corner detection.
 * @param blockSize Size of the pixel neighborhood for corner detection.
 * @param apertureSize Aperture parameter for the Sobel operator.
 * @param k Harris detector free parameter.
 * @param circlethreshold Threshold for drawing circles on corners.
 */
void CornerDetection::setParameters(int blockSize, int apertureSize, double k, int circlethreshold) {
    bool flag;
    while (true) {
        try {
            flag = (blockSize <= 0) || (apertureSize <= 0) || (circlethreshold <= 0 && circlethreshold > 255) || (k <= 0);
            if (flag) {
                throw invalid_argument("Invalid parameters! (Corner Detection)");
            }
            break;
        }
        catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
            cout << "Enter blockSize (0-inf): ";
            cin >> blockSize;
            cout << "Enter apertureSize (0-inf): ";
            cin >> apertureSize;
            cout << "Enter k (0-inf): ";
            cin >> k;
            cout << "Enter circlethreshold (0-255): ";
            cin >> circlethreshold;
            continue;
        }
    }
    this->blockSize = blockSize;this->apertureSize = apertureSize;
    this->circlethreshold = circlethreshold;this->k = k;
}

/**
 * @brief Gets the parameters for corner detection.
 * @return A map containing the parameters with their corresponding values.
 */
map<string, double> CornerDetection::getParameters(void) const {
    return { {"blockSize", blockSize}, {"apertureSize", apertureSize}, {"k", k},
        {"circlethreshold", circlethreshold} };
}

/**
 * @brief Performs Harris corner detection and adds the result to the output images.
 * @param blockSize Size of the pixel neighborhood for corner detection.
 * @param apertureSize Aperture parameter for the Sobel operator.
 * @param k Harris detector free parameter.
 * @param threshold Threshold for corner detection.
 * @param circlethreshold Threshold for drawing circles on corners.
 */
void CornerDetection::harrisCornerDetection(int blockSize, int apertureSize, double k, int circlethreshold) {
    
    setParameters(blockSize, apertureSize, k, circlethreshold);
    cornerHarris(getGrayScale(), harrisImage, getParameters()["blockSize"], getParameters()["apertureSize"], getParameters()["k"]);
    normalize(harrisImage, harrisImage, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
    convertScaleAbs(harrisImage, harrisImage);
    drawCirclesOnCorners(circlethreshold);
    addOutputImage("Harris Image " + to_string(Detection::getandIncrementOutCounter() + 1), harrisImage);
}

/**
 * @brief Draws circles on corners based on the provided threshold.
 * @param threshold Threshold for drawing circles on corners.
 */
void CornerDetection::drawCirclesOnCorners(int threshold) {
    for (int j = 0; j < harrisImage.rows; j++) {
        for (int i = 0; i < harrisImage.cols; i++) {
            if ((int)harrisImage.at<uchar>(j, i) > threshold) {
                circle(harrisImage, Point(i, j), 5, Scalar(0), 2, 8, 0);
            }
        }
    }
}

/**
 * @brief Prints the configuration, including base class and corner detection parameters.
 */
void CornerDetection::printConfig(void) const {
    map<string, double> parametersConfig = getParameters();

    Detection::printConfig();
    cout << endl << "Parameters Config:" << endl;

    for_each(parametersConfig.begin(), parametersConfig.end(), [](pair<string, double> element) {
        cout << element.first << " : " << element.second << endl;
        });
}

/**
 * @brief Destructor for the CornerDetection class.
 */
CornerDetection::~CornerDetection() {}

