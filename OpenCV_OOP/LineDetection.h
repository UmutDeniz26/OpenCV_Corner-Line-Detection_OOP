#pragma once
#include "Detection.h"
class LineDetection :
    public Detection
{
    public:
        LineDetection(string);

        void cannyDetection(int threshold1, int threshold2, int apertureSize);

        void setParameters(int, int, int);
        Mat getCannyImage(void)const ;
        map<string, int> getParameters(void) const;

        void printConfig(void) const;

        ~LineDetection();
    private:
        int threshold1, threshold2, apertureSize;
        Mat cannyImage;

};

