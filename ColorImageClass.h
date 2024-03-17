#ifndef _COLORIMAGECLASS_H_
#define _COLORIMAGECLASS_H_

#include <string>
using namespace std;
#include "ColorClass.h"
#include "RectangleClass.h"
#include "RowColumnClass.h"


class ColorImageClass {
    public:
        // load from a ppm file to init
        bool loadFromPPM(const string &fname);

        // export the color into a PPM file
        bool exportToPPM(const string &fname);

        // annotate rectangle
        void annotateRectangle(RectangleClass &rectangle);

        // annotate pattern
        void annotatePattern(RowColumnClass &patternIdx,
                             ColorClass &patternColor,
                             const string &fname);

        // insert image
        void insertImage(RowColumnClass &imageIdx,
                         ColorClass &transparentColor,
                         const string &fname);

        // get the width of image
        int getNumCol();

        // get the height of image
        int getNumRow();

        // get pixel
        ColorClass getPixel(const int rInd, const int cInd);
              
    private:
        ColorClass **colorMatrix; // 2D dynamic matrix pointer
        string magicNum; // magic number in ppm file
        int numCol; // width of image
        int numRow; // height of image
        
        void allocateMemory();
        void deallocateMemory();
};

#endif