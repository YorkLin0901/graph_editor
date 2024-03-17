#ifndef _COLORCLASS_H
#define _COLORCLASS_H

#include <fstream>
using namespace std;
#include "constants.h"

// describing the color of one pixel
class ColorClass {
    public:
        // initalize color to white
        ColorClass(): valRed(MAX_COLOR_VALUE), valGreen(MAX_COLOR_VALUE), 
                             valBlue(MAX_COLOR_VALUE) { ;
        }; 
        // initalize inRow and inCol to given parameters with clipping
        ColorClass(int inRed, int inGreen, int inBlue);
        
        // get valRed
        int getRed();
        // get valGreen
        int getGreen();
        // get valBlue
        int getBlue();
        // return if the color is the same with a comparedColor
        bool sameWith(ColorClass &comparedColor);
        // set color to Black
        void setToBlack(); 
        // set color to Red
        void setToRed(); 
        // set color to Green
        void setToGreen(); 
        // set color to Blue 
        void setToBlue(); 
        // set color to White
        void setToWhite(); 
        // set color to values
        bool setTo(int inRed, int inGreen, int inBlue); 
        // set color to same color of input
        bool setTo(const ColorClass &inColor); 
        // read color from inFile
        bool readColor(ifstream &inFile);
        // write color to outFile
        void writeColor(ofstream &outFile);  
    private:
        int valRed;
        int valGreen;
        int valBlue;
};



#endif