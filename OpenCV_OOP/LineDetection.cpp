/**
 * @file LineDetection.cpp
 * @brief Implementation of the LineDetection class for detecting lines in images.
 */

#include "LineDetection.h"

using namespace cv;
using namespace std;

/**
 * @brief Constructor for the LineDetection class.
 * @param path The path to the image for line detection.
 */
LineDetection::LineDetection(string path) : Detection(path, "Line Detection"),
threshold1(0), threshold2(0), apertureSize(0) {}

/**
 * @brief Sets the parameters for line detection and checks if they are valid.
 * @param threshold1 First threshold for the Canny edge detector.
 * @param threshold2 Second threshold for the Canny edge detector.
 * @param apertureSize Aperture size for the Sobel operator in the Canny edge detector.
 */
void LineDetection::setParameters(int threshold1, int threshold2, int apertureSize) {
    bool flag;
    while (true) {
        try {
            flag = (threshold1 <= 0 || threshold1 > 255) || (threshold2 <= 0 || threshold2 > 255) || (apertureSize <= 0);
            if (flag) {
                throw invalid_argument("Invalid parameters! (Line Detection)");
            }
            break;
        }
        catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
            cout << "Enter threshold1 (0-255): ";
            cin >> threshold1;
            cout << "Enter threshold2 (0-255): ";
            cin >> threshold2;
            cout << "Enter apertureSize (0-inf): ";
            cin >> apertureSize;
            continue;
        }
    }
    this->threshold1 = threshold1;
    this->threshold2 = threshold2;
    this->apertureSize = apertureSize;
}

/**
 * @brief Gets the parameters for line detection.
 * @return A map containing the parameters with their corresponding values.
 */
map<string, int> LineDetection::getParameters(void) const {
    return { {"threshold1", threshold1}, {"threshold2", threshold2}, {"apertureSize", apertureSize} };
}

/**
 * @brief Gets the Canny edge detection image.
 * @return The Canny edge detection result.
 */
Mat LineDetection::getCannyImage(void) const {
    return cannyImage;
}

/**
 * @brief Performs Canny edge detection and adds the result to the output images.
 * @param threshold1 First threshold for the Canny edge detector.
 * @param threshold2 Second threshold for the Canny edge detector.
 * @param apertureSize Aperture size for the Sobel operator in the Canny edge detector.
 */
void LineDetection::cannyDetection(int threshold1, int threshold2, int apertureSize) {
    setParameters(threshold1, threshold2, apertureSize);
    Canny(getGrayScale(), cannyImage, getParameters()["threshold1"], getParameters()["threshold2"], getParameters()["apertureSize"]);
    addOutputImage("Canny Image " + to_string(Detection::getandIncrementOutCounter() + 1), getCannyImage());
}

/**
 * @brief Prints the configuration, including base class and line detection parameters.
 */
void LineDetection::printConfig(void) const {
    Detection::printConfig();

    cout << endl << "Parameters Config:" << endl;
    map<string, int> parametersConfig = getParameters();

    for_each(parametersConfig.begin(), parametersConfig.end(), [](pair<string, int> element) {
        cout << element.first << " : " << element.second << endl;
        });
}

/**
 * @brief Destructor for the LineDetection class.
 */
LineDetection::~LineDetection() {}
