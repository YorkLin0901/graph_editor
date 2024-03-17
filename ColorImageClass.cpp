#include <string>
#include <iostream>
#include <fstream>
using namespace std;
#include "constants.h"
#include "ColorImageClass.h"
#include "ColorClass.h"
#include "RectangleClass.h"
#include "RowColumnClass.h"

// allocate memory
void ColorImageClass::allocateMemory() {
    colorMatrix = new ColorClass*[numRow];
    for (int rInd = 0; rInd < numRow; rInd++) {
        colorMatrix[rInd] = new ColorClass[numCol];
    }
}

// deallocate memory
void ColorImageClass::deallocateMemory() {
    for (int rInd = 0; rInd < numRow; rInd++) {
        delete [] colorMatrix[rInd];
    }
    delete [] colorMatrix;
}

// load from a ppm file to init
bool ColorImageClass::loadFromPPM(const string &fname) {
    // read using ifstream
    ifstream inFile;
    inFile.open(fname.c_str());

    // error check: successfully opened
    if (inFile.fail()) {
        cout << "Failed to open " << fname << endl;
        inFile.close();
        return false;
    }

    // read magic number
    inFile >> magicNum;
    if (inFile.eof()) { // error check: eof
        cout << "EOF before reading magic number" << endl;
        inFile.close();
        return false;
    }
    else if (magicNum != MAGIC_NUM_SETTING) {
        cout << "Error found when trying to read magic number - expected " 
        << MAGIC_NUM_SETTING << " but found " << magicNum << endl;
        inFile.close();
        return false;
    }

    // read width
    inFile >> numCol;
    if (inFile.eof()) { // error check: eof
        cout << "EOF before reading width" << endl;
        inFile.close();
        return false;
    }
    else if (numCol <= 0) { // error check: input of width
        cout << "invalid width input" << endl;
        inFile.close();
        return false;
    }

    // read height
    inFile >> numRow;
    if (inFile.eof()) { // error check: eof
        cout << "EOF before reading height" << endl;
        inFile.close();
        return false;
    }
    else if (numRow <= 0) { // error check: input of width
        cout << "invalid height input" << endl;
        inFile.close();
        return false;
    }

    // read max color value
    int max_color_value;
    inFile >> max_color_value;
    if (inFile.eof()) { // error check: eof
        cout << "EOF before reading max color value" << endl;
        inFile.close();
        return false;
    } 
    else if (max_color_value != MAX_COLOR_VALUE) {
        cout << "Error found when trying to read max color value - expected "
        << MAX_COLOR_VALUE << " but found " << max_color_value << endl;
        inFile.close();
        return false;
    }

    allocateMemory();

    // read color of each pixel
    for (int rInd = 0; rInd < numRow; rInd++) {
        for (int cInd = 0; cInd < numCol; cInd++) {
            // fill in ColorClass
            if (!colorMatrix[rInd][cInd].readColor(inFile)) {
                cout << "error found at row(" << rInd << ") col(" 
                << cInd << ")" << endl;

                deallocateMemory();

                return false;
            }
        }
    }

    // error check: inconsistent number of pixel with set number
    int checkMoreVal;
    
    inFile >> checkMoreVal;
    if (!inFile.fail()) {
        cout << "Pixel number is more than as set" << endl;
        inFile.close();
        deallocateMemory();
        return false;
    }
    
    // return true status if every thing is completed
    inFile.close();
    return true;
}

// Export the color into a PPM file
bool ColorImageClass::exportToPPM(const string &fname) {
    // Export to output file
    ofstream outFile;
    outFile.open(fname.c_str());

    if (outFile.fail()) {
        cout << "Unable to open output file" << endl;
        return false;
    }

    // Write into file
    outFile << magicNum << endl;
    outFile << numCol << " " << numRow << endl;
    outFile << MAX_COLOR_VALUE << endl;

    for (int rInd = 0; rInd < numRow; rInd++) {
        for (int cInd = 0; cInd < numCol; cInd++) {
            colorMatrix[rInd][cInd].writeColor(outFile);
        }
        outFile << endl;
    }    

    // Return true if everything is completed
    outFile.close();
    return true;
}

// Annotate rectangle
void ColorImageClass::annotateRectangle(RectangleClass &rectangle) {
    // Insert rectangle info
    int insertRow = rectangle.getLeftCornerRow();
    int insertCol = rectangle.getLeftCornerCol();
    int insertNumRow = rectangle.getNumRow();
    int insertNumCol = rectangle.getNumCol();
    ColorClass rectangleColor = rectangle.getColor();
    bool isFilled = rectangle.getIsFilled();

    // Out of scope: out left upper corner
    if ((insertRow < 0) || (insertCol < 0)) {
        cout << "Rectangle out of scope" << endl;
        return;
    }
    // Out of scope: out right lower corner
    else if ((insertRow + insertNumRow > numRow)
        || (insertRow + insertNumCol > numCol)) {
        cout << "Rectangle out of scope" << endl;
        return;
    }

    // Draw filled rectangle
    if (isFilled) {
        for (int rInd = 0; rInd < insertNumRow; rInd++) {
            for (int cInd = 0; cInd < insertNumCol; cInd++) {
                colorMatrix[rInd + insertRow][cInd + insertCol]
                .setTo(rectangleColor);
            }
        }
    }
    // Draw non-filled rectangle
    else {
        for (int rInd = 0; rInd < insertNumRow; rInd++) {
            for (int cInd = 0; cInd < insertNumCol; cInd++) {
                // Draw the upper and lower boundary
                if ((rInd == 0) || (rInd == insertNumRow - IDX_ADJUST)) {
                    colorMatrix[rInd + insertRow][cInd + insertCol]
                    .setTo(rectangleColor);
                }
                // Draw the left and right boundary
                else {
                    if ((cInd == 0) || (cInd == insertNumCol - IDX_ADJUST)) {
                        colorMatrix[rInd + insertRow][cInd + insertCol]
                        .setTo(rectangleColor);
                    }
                }
            }
        }
    }
}

// annotate pattern
void ColorImageClass::annotatePattern(RowColumnClass &patternIdx,
                                      ColorClass &patternColor,
                                      const string &fname) {
    // index info
    int insertRow = patternIdx.getRow();
    int insertCol = patternIdx.getCol();
    int insertNumRow;
    int insertNumCol;

    // read using ifstream
    ifstream inFile;
    ifstream inFileSec;
    inFile.open(fname.c_str());

    if (inFile.fail()) {
        cout << "failed to open pattern file: " << fname << endl;
        return;
    }

    // read the number of col
    inFile >> insertNumCol;
    if (inFile.fail()) {
        cout << "invalid number of col" << endl;
        return;
    }

    if (inFile.eof()) {
        cout << "EOF before reading number of col" << endl;
        return;
    }

    if (insertNumCol <= 0) {
        cout << "invalid number of col" << endl;
        return;
    }

    // read the number of row
    inFile >> insertNumRow;
    if (inFile.fail()) {
        cout << "invalid number of row" << endl;
        return;
    }

    if (inFile.eof()) {
        cout << "EOF before reading number of row" << endl;
        return;
    }

    if (insertNumRow <= 0) {
        cout << "invalid number of row" << endl;
        return;
    }

    // left upper corner of pattern out of scope
    if (insertRow < 0 || insertCol < 0) {
        cout << "Pattern out of scope" << endl;
        return;
    }
    // right lower corner of pattern out of scope
    else if ((insertRow + insertNumRow > numRow)
             || (insertCol + insertNumCol > numCol)) {
        cout << "Pattern out of scope" << endl;
        return;
    } 

    // read first time to check number of values
    for (int rInd = 0; rInd < insertNumRow; rInd++) {
        for (int cInd = 0; cInd < insertNumCol; cInd++) {
            int patternBinary;

            inFile >> patternBinary;
            if (inFile.fail() || (patternBinary != PATTERN_NONE_VALUE
                                  && patternBinary != PATTERN_FILLED_VALUE)) {
                cout << "error when reading binary at row(" << rInd
                << ") col(" << cInd << ")" << endl;
                return;
            }

            if (inFile.eof()) {
                cout << "EOF before read all the data as set" << endl;
                return;
            }
        }
    }

    int checkMoreVal;
    inFile >> checkMoreVal;
    if (!inFile.fail()) {
        cout << "Binary number is more than as set: read additional " 
        << checkMoreVal << endl;
        return;
    }

    // read second time to fill in the color
    inFileSec.open(fname.c_str());

    inFileSec >> insertNumCol >> insertNumRow;
    for (int rInd = 0; rInd < insertNumRow; rInd++) {
        for (int cInd = 0; cInd < insertNumCol; cInd++) {
            int patternBinary;

            inFileSec >> patternBinary;
            // fill in the color if the binary is 1
            if (patternBinary == PATTERN_FILLED_VALUE) {
                colorMatrix[rInd + insertRow][cInd + insertCol]
                .setTo(patternColor);
            }
        }
    }

    // out of scope: out left upper corner
    if ((insertRow < 0) || (insertCol < 0)) {
        cout << "Pattern out of scope" << endl;
        return;
    }
    // out of scope: out right lower corner
    else if ((insertRow + insertNumRow > numRow)
        || (insertRow + insertNumCol > numCol)) {
        cout << "Pattern out of scope" << endl;
        return;
    }  
}

// insert image
void ColorImageClass::insertImage(RowColumnClass &imageIdx,
                                  ColorClass &transparentColor,
                                  const string &fname) {
    // index info
    int insertRow = imageIdx.getRow();
    int insertCol = imageIdx.getCol();
    ColorImageClass insertImage;

    if (!insertImage.loadFromPPM(fname)) {
        return;
    }

    // left upper corner of image out of scope
    if (insertRow < 0 || insertCol < 0) {
        cout << "image inserted out of scope" << endl;
        return;
    }
    // right lower corner of image out of scope
    else if ((insertRow + insertImage.getNumRow() > numRow)
             || (insertCol + insertImage.getNumCol() > numCol)) {
        cout << "image inserted out of scope" << endl;
        return;
    } 

    for (int rInd = 0; rInd < insertImage.getNumRow(); rInd++) {
        for (int cInd = 0; cInd < insertImage.getNumCol(); cInd++) {
            ColorClass pixelColor;
            
            pixelColor.setTo(insertImage.getPixel(rInd, cInd));
            // overlap the color if the pixel is not transparent color
            if (!pixelColor.sameWith(transparentColor)) {
                colorMatrix[rInd + insertRow][cInd + insertCol]
                .setTo(pixelColor);
            }
        }
    }
}

// get the width of image
int ColorImageClass::getNumCol() {
    return numCol;
}

// get the height of image
int ColorImageClass::getNumRow() {
    return numRow;
}

// get pixel
ColorClass ColorImageClass::getPixel(const int rInd, const int cInd) {
    return colorMatrix[rInd][cInd];
}

              