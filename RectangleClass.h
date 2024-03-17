#ifndef _RECTANGLECLASS_H_
#define _RECTANGLECLASS_H_

using namespace std;
#include "ColorClass.h"

class RectangleClass {
    public:
        // initialize leftCornerRow, leftCornerCol, numRow, numCol
        void initialize(int inRowInd, int inColInd, int inNumRow, int inNumCol,
                        ColorClass &inRectangleColor, bool inIsFilled);

        // get leftCornerRow
        int getLeftCornerRow();
        // get leftCornerCol
        int getLeftCornerCol();
        // get numRow
        int getNumRow();
        // get numCol
        int getNumCol();
        // get color
        ColorClass getColor();
        // get isFilled
        bool getIsFilled();
        
    private:
        int leftCornerRow;
        int leftCornerCol;
        int numRow;
        int numCol;
        ColorClass rectangleColor;
        bool isFilled;
};

#endif