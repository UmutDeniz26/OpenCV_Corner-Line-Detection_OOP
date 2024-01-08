/**
 * @file Detection.cpp
 * @brief Implementation of the Detection class for common image detection operations.
 */

#include "Detection.h"

using namespace cv;
using namespace std;

/**
 * @brief Static member initialization for the output counter.
 */
int Detection::outCounter = 0;

/**
 * @brief Constructor for the Detection class with a file path.
 * @param path The path to the image for detection.
 * @param title The title of the detection process.
 */
Detection::Detection(string path, string title) : CommonProcess(path, title) {}

/**
 * @brief Constructor for the Detection class with a pre-loaded image.
 * @param image The image for detection.
 * @param title The title of the detection process.
 */
Detection::Detection(Mat image, string title) : CommonProcess(image, title) {}

/**
 * @brief Prints the configuration, including base class and output image titles.
 */
void Detection::printConfig(void) const {
    CommonProcess::printConfig();
    cout << endl << "Output Images (" << outputImages.size() << "):" << endl;
    for_each(outputImages.begin(), outputImages.end(), [](pair<string, Mat> element) {
        cout << " Title: " << element.first << endl;
        });
}

/**
 * @brief Adds an output image with a given title to the output images container.
 * @param title The title of the output image.
 * @param image The image to be added as output.
 */
void Detection::addOutputImage(string title, const Mat& image) {
    Mat clonedImage = image.clone(); // This is very important, otherwise the image will be duplicated in the map
    outputImages.insert(pair<string, Mat>(title, clonedImage));
}

/**
 * @brief Shows all the output images using OpenCV's `imshow` function.
 */
void Detection::showOutputImages(void) const {
    for_each(outputImages.begin(), outputImages.end(), [](pair<string, Mat> element) {
        imshow(element.first, element.second);
        });
}

/**
 * @brief Gets and increments the static output counter.
 * @return The current value of the output counter before incrementing.
 */
int Detection::getandIncrementOutCounter(void) {
    return outCounter++;
}

/**
 * @brief Destructor for the Detection class.
 */
Detection::~Detection() {}

