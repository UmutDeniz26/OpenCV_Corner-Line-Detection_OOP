/**
 * @file CommonProcess.cpp
 * @brief Implementation of the CommonProcess class for common image processing operations.
 */

#include "CommonProcess.h"

using namespace cv;
using namespace std;

/**
 * @brief Constructor for the CommonProcess class with a file path.
 * @param path The path to the image for common processing.
 * @param titleIn The title of the image.
 */
CommonProcess::CommonProcess(string path, string titleIn) : title(titleIn), filePath(path) {
    loadRawRGBImage(path);
}

/**
 * @brief Constructor for the CommonProcess class with a pre-loaded image.
 * @param image The image for common processing.
 * @param titleIn The title of the image.
 */
CommonProcess::CommonProcess(Mat image, string titleIn) : title(titleIn), rawRGBImage(image), filePath("") {
    setSize(rawRGBImage.size());
}

/**
 * @brief Gets the grayscale version of the raw RGB image.
 * @return The grayscale image.
 */
Mat CommonProcess::getGrayScale() const {
    Mat grayScaleImage;
    cvtColor(rawRGBImage, grayScaleImage, COLOR_BGR2GRAY);
    return grayScaleImage;
}

/**
 * @brief Gets a resized version of the raw RGB image.
 * @param size The size to which the image should be resized.
 * @return The resized image.
 */
Mat CommonProcess::getResizedImage(Size size) const {
    Mat resizedImage;
    resize(rawRGBImage, resizedImage, size);
    return resizedImage;
}

/**
 * @brief Gets the file path of the raw RGB image.
 * @return The file path.
 */
string CommonProcess::getFilePath() const {
    return filePath;
}

/**
 * @brief Gets the raw RGB image.
 * @return The raw RGB image.
 */
Mat CommonProcess::getRawRGBImage() {
    return rawRGBImage;
}

/**
 * @brief Gets the size of the raw RGB image.
 * @return The size of the image.
 */
Size CommonProcess::getSize() const {
    return size;
}

/**
 * @brief Gets the title of the image.
 * @return The title of the image.
 */
string CommonProcess::getTitle() const {
    return title;
}

/**
 * @brief Sets the file path of the raw RGB image.
 * @param path The new file path.
 */
void CommonProcess::setFilePath(string path) {
    filePath = path;
}

/**
 * @brief Sets the title of the image.
 * @param titleIn The new title.
 */
void CommonProcess::setTitle(string titleIn) {
    title = titleIn;
}

/**
 * @brief Sets the size of the raw RGB image.
 * @param sizeIn The new size.
 */
void CommonProcess::setSize(Size sizeIn) {
    size = sizeIn;
}

/**
 * @brief Sets the raw RGB image.
 * @param image The new raw RGB image.
 */
void CommonProcess::setRawRGBImage(Mat image) {
    setSize(image.size());
    rawRGBImage = image;
}

/**
 * @brief Loads the raw RGB image from a file path.
 * @param path The file path of the image.
 */
void CommonProcess::loadRawRGBImage(string path) {
    try {
        rawRGBImage = imread(path);
        setSize(rawRGBImage.size());
    }
    catch (invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
}

/**
 * @brief Displays the raw RGB image in a window with the given name.
 * @param windowName The name of the window.
 */
void CommonProcess::showImage(string windowName) const {
    imshow(windowName, rawRGBImage);
}

/**
 * @brief Prints the configuration information of the image.
 */
void CommonProcess::printConfig() const {
    cout << endl << "------------------------------------" << endl << "Title: " << title << endl;
    cout << "Image size: " << size << endl;
}

/**
 * @brief Destructor for the CommonProcess class.
 */
CommonProcess::~CommonProcess() {}

