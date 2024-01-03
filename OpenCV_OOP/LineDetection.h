#pragma once
#include "Detection.h"
class LineDetection :
    public Detection
{
    public:
        LineDetection(string);

        void cannyDetection(int treshold1, int treshold2, int apertureSize);

        virtual void showImage(string) const;

        ~LineDetection();
    protected:
        Mat cannyImage;

};

