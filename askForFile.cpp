#include <iostream>
#include <string>
using namespace std;
#include "constants.h"
#include "askForFile.h"

// ask for file name based on mode
bool askForFile(string &inputFileName, int mode) {
    if (mode == USER_CHOICE_ANNOTATE_PATTERN) {
        cout << "Enter string for file name containing pattern: ";
    }
    else if (mode == USER_CHOICE_INSERT_IMAGE) {
        cout << "Enter string for file name of PPM image to insert: "; 
    }
    else if (mode == USER_CHOICE_WRITE_OUT) {
        cout << "Enter string for PPM file name to output: "; 
    }
    
    cin >> inputFileName;
    // check bad input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(MAX_INT, NEW_LINE_CHAR);
        cout << "Fail to input file name" << endl;
        return false;
    }

    return true;
}