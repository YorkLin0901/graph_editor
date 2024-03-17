#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;
#include "constants.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "ColorImageClass.h"
#include "RectangleClass.h"
#include "askForFile.h"
#include "askForColor.h"
#include "askForInsertIdx.h"

// Author: Yukai Lin
// Date: 10/28/2023
// Purpose: This project is to do some modification on images.

int main() {
    string fname; // file to read
    string outputName; // file to output
    bool doContinue = true; 
    ColorImageClass myImage; // image to be stored

    // ask for a ppm image file name
    cout << "Enter string for PPM image file name to load: ";

    cin >> fname;
    // check bad input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(MAX_INT, NEW_LINE_CHAR);
        cout << "Fail to input file name" << endl;
        return false;
    }

    // end if fail to load
    if (!myImage.loadFromPPM(fname)) { 
        exit(1);
    }

    // show the loop of menu system
    while (doContinue) {
        cout << USER_CHOICE_ANNOTATE_RECTANGLE 
        << ". Annotate image with rectangle" << endl;
        cout << USER_CHOICE_ANNOTATE_PATTERN 
        << ". Annotate image with pattern from file" << endl;
        cout << USER_CHOICE_INSERT_IMAGE 
        << ". Insert another image" << endl;
        cout << USER_CHOICE_WRITE_OUT 
        << ". Write out current image" << endl;
        cout << USER_CHOICE_EXIT 
        << ". Exit the program" << endl;
        
        int inOption; // option to input
        bool validInputFound = false;
        while (!validInputFound) {
            // ask for option of menu
            cout << "Enter int for main menu choice: ";
            
            cin >> inOption;
            // check bad input
            if (cin.fail()) {
                cin.clear();
                cin.ignore(MAX_INT, NEW_LINE_CHAR);
                cout << "Fail state! Try again." << endl;
            }
            else {
                validInputFound = true;
            }
        }

        // Annotate image with rectangle
        if (inOption == USER_CHOICE_ANNOTATE_RECTANGLE) {
            ColorClass rectangleColor;
            RectangleClass rectangleForInsert;
            bool isFilled; 
            bool doContinueInsertRectangle = true; // stop inserting if false
            int rectangleInsertOption; // user option in method of inserting
            int rectangleFillOption; // user option in choosing filled or not
            int rIndLeft, cIndLeft, numRow, numCol; // attribute input

            // Ask for option of rectangle inserting method
            cout << USER_CHOICE_RECTANGLE_TWO_CORNER
            << ". Specify upper left and lower right corners of rectangle"
            << endl;
            cout << USER_CHOICE_RECTANGLE_CORNER_DIM
            << ". Specify upper left corner and dimensions of rectangle"
            << endl;
            cout << USER_CHOICE_RECTANGLE_CENTER_DIM
            << ". Specify extent from center of rectangle"
            << endl;
            cout << "Enter int for rectangle specification method: ";

            cin >> rectangleInsertOption;
            // bad data input
            if (cin.fail()) {
                cin.clear();
                cin.ignore(MAX_INT, NEW_LINE_CHAR);
                cout << "Fail to input rectangle specification method." << endl;
                doContinueInsertRectangle = false;
            }
            
            if (doContinueInsertRectangle) {
                // Specify upper left and lower right corners of rectangle
                if (rectangleInsertOption == USER_CHOICE_RECTANGLE_TWO_CORNER) {
                    int rIndRight, cIndRight; // center index

                    cout << "Enter upper left corner row and column: ";

                    cin >> rIndLeft;
                    // bad data input
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(MAX_INT, NEW_LINE_CHAR);
                        cout << "Fail to get info for upper left row index"
                        << endl;
                        doContinueInsertRectangle = false;
                    }

                    if (doContinueInsertRectangle) {
                        cin >> cIndLeft;
                        // bad data input
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(MAX_INT, NEW_LINE_CHAR);
                            cout << "Fail to get info for upper left col index"
                            << endl;
                            doContinueInsertRectangle = false;
                        }
                    }

                    if (doContinueInsertRectangle) {
                        cout << "Enter lower right corner row and column: ";

                        cin >> rIndRight;
                        // bad data input
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(MAX_INT, NEW_LINE_CHAR);
                            cout << "Fail to get info for lower right row index"
                            << endl;
                            doContinueInsertRectangle = false;
                        }
                    }

                    if (doContinueInsertRectangle) {
                        cin >> cIndRight;
                        // bad data input
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(MAX_INT, NEW_LINE_CHAR);
                            cout << "Fail to get info for lower right col index"
                            << endl;
                            doContinueInsertRectangle = false;
                        }
                    }

                    if (doContinueInsertRectangle) {
                        // revert to attribute of rectangle
                        numRow = rIndRight - rIndLeft + IDX_ADJUST;
                        numCol = cIndRight - cIndLeft + IDX_ADJUST;
                    }
                }
                // Specify upper left corner and dimensions of rectangle
                else if (rectangleInsertOption 
                        == USER_CHOICE_RECTANGLE_CORNER_DIM) {
                    cout << "Enter upper left corner row and column: ";

                    cin >> rIndLeft;
                    // bad data input
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(MAX_INT, NEW_LINE_CHAR);
                        cout << "Fail to get info for upper left row index" 
                        << endl;
                        doContinueInsertRectangle = false;
                    }

                    if (doContinueInsertRectangle) {
                        cin >> cIndLeft;
                        // bad data input
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(MAX_INT, NEW_LINE_CHAR);
                            cout << "Fail to get info for upper left col index" 
                            << endl;
                            doContinueInsertRectangle = false;
                        }
                    }

                    if (doContinueInsertRectangle) {
                        cout << "Enter int for number of rows: ";

                        cin >> numRow;
                        // bad data input
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(MAX_INT, NEW_LINE_CHAR);
                            cout << "Fail to get info for numRow." << endl;
                            doContinueInsertRectangle = false;
                        }
                    }

                    if (doContinueInsertRectangle) {
                        cout << "Enter int for number of columns: ";

                        cin >> numCol;
                        // bad data input
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(MAX_INT, NEW_LINE_CHAR);
                            cout << "Fail to get info for numCol." << endl;
                            doContinueInsertRectangle = false;
                        }
                    }
                }
                // Specify extent from center of rectangle
                else if (rectangleInsertOption
                        == USER_CHOICE_RECTANGLE_CENTER_DIM) {
                    int rIndCenter, cIndCenter, halfNumRow, halfNumCol;

                    cout << "Enter rectangle center row and column: ";

                    cin >> rIndCenter;
                    // bad data input
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(MAX_INT, NEW_LINE_CHAR);
                        cout << "Fail to get info for center row index." 
                        << endl;
                        doContinueInsertRectangle = false;
                    }
                    
                    if (doContinueInsertRectangle) {
                        cin >> cIndCenter;
                        // bad data input
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(MAX_INT, NEW_LINE_CHAR);
                            cout << "Fail to get info for center col index." 
                            << endl;
                            doContinueInsertRectangle = false;
                        }
                    }

                    if (doContinueInsertRectangle) {
                        cout << "Enter int for half number of rows: ";
                        cin >> halfNumRow;
                        // bad data input
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(MAX_INT, NEW_LINE_CHAR);
                            cout << "Fail to get info for numRow." << endl;
                            doContinueInsertRectangle = false;
                        }
                    }

                    if (doContinueInsertRectangle) {
                        cout << "Enter int for half number of columns: ";
                        cin >> halfNumCol;
                        // bad data input
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(MAX_INT, NEW_LINE_CHAR);
                            cout << "Fail to get info for numCol." << endl;
                            doContinueInsertRectangle = false;
                        }
                    }

                    if (doContinueInsertRectangle) {
                        // revert to attribute of rectangle
                        rIndLeft = rIndCenter - halfNumRow;
                        cIndLeft = cIndCenter - halfNumCol;
                        numRow = 2 * halfNumRow;
                        numCol = 2 * halfNumCol;
                    }
                }
                // Invalid input
                else {
                    cout << "Invalid input for rectangle insert option." 
                    << endl;
                    doContinueInsertRectangle = false;
                }
            }

            if (doContinueInsertRectangle) {
                // Ask for the color of rectangle
                doContinueInsertRectangle = askForColor(rectangleColor, 
                                                        inOption);
            }

            if (doContinueInsertRectangle) {
                // Ask for whether the rectangle is filled
                cout << USER_CHOICE_NON_FILLED_RECTANGLE << ". No" << endl;
                cout << USER_CHOICE_FILLED_RECTANGLE << ". Yes" << endl;
                cout << "Enter int for rectangle fill option: ";

                cin >> rectangleFillOption;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(MAX_INT, NEW_LINE_CHAR);
                    cout << "fail to input rectangle fill option" << endl;
                    doContinueInsertRectangle = false;
                }
            }

            if (doContinueInsertRectangle) {
                if (rectangleFillOption 
                    == USER_CHOICE_NON_FILLED_RECTANGLE) {
                    isFilled = false;
                }
                else if (rectangleFillOption 
                        == USER_CHOICE_FILLED_RECTANGLE) {
                    isFilled = true;
                }
                // Invalid input
                else {
                    cout << "Invalid input for rectangle fill option." << endl;
                    doContinueInsertRectangle = false;
                }
            }
            if (doContinueInsertRectangle) {
                // annotate rectangle
                rectangleForInsert.initialize(rIndLeft, cIndLeft, 
                                              numRow, numCol,
                                              rectangleColor, isFilled);
                myImage.annotateRectangle(rectangleForInsert);
            }

        }
        // Annotate image with pattern from file
        else if (inOption == USER_CHOICE_ANNOTATE_PATTERN) {
            bool doContinueInsertPattern = true;
            ColorClass patternColor;
            RowColumnClass patternIdx;
            string insertPatternFile; // file name of pattern file

            // name of insert pattern file
            doContinueInsertPattern = askForFile(insertPatternFile, inOption);

            // input col and row
            if (doContinueInsertPattern) {
                // insert index of pattern
                doContinueInsertPattern = askForInsertIdx(patternIdx, inOption);
            }

            // input color
            if (doContinueInsertPattern) {
                // Ask for the color of pattern
                doContinueInsertPattern = askForColor(patternColor, inOption);
            }

            // annotate pattern
            if (doContinueInsertPattern) {
                myImage.annotatePattern(patternIdx, patternColor, 
                                        insertPatternFile);
            }
        }
        // Insert another image
        else if (inOption == USER_CHOICE_INSERT_IMAGE) {
            bool doContinueInsertImage = true;
            ColorClass transparentColor;
            RowColumnClass imageIdx;
            string insertImageFile; // file name of inserted image

            // name of insert image file
            doContinueInsertImage = askForFile(insertImageFile, inOption);

            if (doContinueInsertImage) {
                // insert index of image
                doContinueInsertImage = askForInsertIdx(imageIdx, inOption);
            }
            
            // Ask for the color of transparent color
            if (doContinueInsertImage) {
                // insert index of pattern
                doContinueInsertImage = askForColor(transparentColor, inOption);
            }

            // insert the image
            if (doContinueInsertImage) {
                myImage.insertImage(imageIdx, transparentColor, 
                                    insertImageFile);
            }
        }
        // Write out current image
        else if (inOption == USER_CHOICE_WRITE_OUT) {
            // Ask for the output file name
            if (askForFile(outputName, inOption)) {
                myImage.exportToPPM(outputName);
            }
        }
        // Exit the program
        else if (inOption == USER_CHOICE_EXIT) {
            cout << "Thank you for using this program" << endl;
            doContinue = false;
        }
        // bad data input
        else {
            cout << "Invalid input for menu option." << endl;
        }
    }
    return 0;
}


