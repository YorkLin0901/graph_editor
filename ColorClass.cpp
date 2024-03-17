#include <iostream>
#include <fstream>
using namespace std;
#include "ColorClass.h"
#include "constants.h"
#include "doClip.h"

// ctor with given value
ColorClass::ColorClass(int inRed, int inGreen, int inBlue) {
    // clipping
    doClip(inRed, inGreen, inBlue);
    
    // set value
    valRed = inRed;
    valGreen = inGreen;
    valBlue = inBlue;
}

// get valRed
int ColorClass::getRed() {
    return valRed;
}

// get valGreen
int ColorClass::getGreen() {
    return valGreen;
}

// get valBlue
int ColorClass::getBlue() {
    return valBlue;
}

// return if the color is the same with a comparedColor
bool ColorClass::sameWith(ColorClass &comparedColor) {
    return (valRed == comparedColor.getRed()
            && valGreen == comparedColor.getGreen()
            && valBlue == comparedColor.getBlue());
}

// set color to Black
void ColorClass::setToBlack() {
    valRed = MIN_COLOR_VALUE;
    valGreen = MIN_COLOR_VALUE;
    valBlue = MIN_COLOR_VALUE;
}

// set color to Red
void ColorClass::setToRed() {
    valRed = MAX_COLOR_VALUE;
    valGreen = MIN_COLOR_VALUE;
    valBlue = MIN_COLOR_VALUE;
}

// set color to Green
void ColorClass::setToGreen() {
    valRed = MIN_COLOR_VALUE;
    valGreen = MAX_COLOR_VALUE;
    valBlue = MIN_COLOR_VALUE;
}

// set color to Blue 
void ColorClass::setToBlue() {
    valRed = MIN_COLOR_VALUE;
    valGreen = MIN_COLOR_VALUE;
    valBlue = MAX_COLOR_VALUE;
}

// set color to White
void ColorClass::setToWhite() {
    valRed = MAX_COLOR_VALUE;
    valGreen = MAX_COLOR_VALUE;
    valBlue = MAX_COLOR_VALUE;
}

// set color to values
bool ColorClass::setTo(int inRed, int inGreen, int inBlue) {
    // init clipping status
    bool didClip = false;

    // try to clip
    didClip = doClip(inRed, inGreen, inBlue);

    // set value
    valRed = inRed;
    valGreen = inGreen;
    valBlue = inBlue;

    return didClip;
}

// set color to same color of input
bool ColorClass::setTo(const ColorClass &inColor) {
    // init clipping status
    bool didClip = false;

    //set value
    valRed = inColor.valRed;
    valGreen = inColor.valGreen;
    valBlue = inColor.valBlue;

    return didClip;
}

// read color from inFile
bool ColorClass::readColor(ifstream &inFile) {
    // input values of RGB
    int inRed, inGreen, inBlue;

    inFile >> inRed >> inGreen >> inBlue;
    // error check: EOF before last pixel
    if (inFile.eof()) {
        cout << "EOF before reading all the pixels as set. ";
        inFile.close();
        return false;
    }
    // error check: fail to read
    else if (inFile.fail()) {
        cout << "Error reading pixel data. ";
        inFile.close();
        return false;
    }
    // error check: color value out of scope
    else if ((MIN_COLOR_VALUE > inRed) || (MAX_COLOR_VALUE < inRed)
            || (MIN_COLOR_VALUE > inGreen) || (MAX_COLOR_VALUE < inGreen)
            || (MIN_COLOR_VALUE > inBlue) || (MAX_COLOR_VALUE < inBlue)) {
        cout << "Pixel color value out of scope. ";
        inFile.close();
        return false;
    }

    // adjust color
    valRed = inRed;
    valGreen = inGreen;
    valBlue = inBlue;

    return true;
}

// write color to outFile
void ColorClass::writeColor(ofstream &outFile) {
    outFile << valRed << " " << valGreen << " " << valBlue << " ";
}