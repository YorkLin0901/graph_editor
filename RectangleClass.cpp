using namespace std;
#include "RectangleClass.h"
#include "ColorClass.h"

// initialize leftCornerRow, leftCornerCol, numRow, numCol
void RectangleClass::initialize(int inRowInd, int inColInd, 
                               int inNumRow, int inNumCol,
                               ColorClass &inRectangleColor, bool inIsFilled) {
    leftCornerRow = inRowInd;
    leftCornerCol = inColInd;
    numRow = inNumRow;
    numCol = inNumCol;
    rectangleColor.setTo(inRectangleColor);
    isFilled = inIsFilled;
}

// get leftCornerRow
int RectangleClass::getLeftCornerRow() {
    return leftCornerRow;
}

// get leftCornerCol
int RectangleClass::getLeftCornerCol() {
    return leftCornerCol;
}

// get numRow
int RectangleClass::getNumRow() {
    return numRow;
}

// get numCol
int RectangleClass::getNumCol() {
    return numCol;
}

// get color
ColorClass RectangleClass::getColor() {
    return rectangleColor;
}

// get isFilled
bool RectangleClass::getIsFilled() {
    return isFilled;
}