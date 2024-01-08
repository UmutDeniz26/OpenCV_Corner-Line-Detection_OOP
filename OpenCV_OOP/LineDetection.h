#pragma once
#include "Detection.h"
class LineDetection :
    public Detection
{
    public:
        LineDetection(string);

        void cannyDetection(int treshold1, int treshold2, int apertureSize);

        void setParameters(int, int, int);
        map<string, int> getParameters(void) const;

        void printConfig(void) const;

        ~LineDetection();
    private:
        int treshold1, treshold2, apertureSize;
        Mat cannyImage;

};

