#include <iostream>
using namespace std;
#include "askForColor.h"
#include "ColorClass.h"

// ask for color input based on mode
bool askForColor(ColorClass &inputColor, int mode) {
    // Ask for the color of pattern
    cout << USER_OPTION_RED << ". Red" << endl;
    cout << USER_OPTION_GREEN << ". Green" << endl;
    cout << USER_OPTION_BLUE << ". Blue" << endl;
    cout << USER_OPTION_BLACK << ". Black" << endl;
    cout << USER_OPTION_WHITE << ". White" << endl;

    int inputColorOption;
    if (mode == USER_CHOICE_ANNOTATE_RECTANGLE) {
        cout << "Enter int for rectangle color: ";
    }
    else if (mode == USER_CHOICE_ANNOTATE_PATTERN) {
        cout << "Enter int for pattern color: ";
    }
    else if (mode == USER_CHOICE_INSERT_IMAGE) {
        cout << "Enter int for transparecy color: ";
    }

    cin >> inputColorOption;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(MAX_INT, NEW_LINE_CHAR);
        cout << "Fail to input color optoin" << endl;
        return false;
    }

    // Set color to Red
    if (inputColorOption == USER_OPTION_RED) {
        inputColor.setToRed();
    }
    // Set color to Green
    else if (inputColorOption == USER_OPTION_GREEN) {
        inputColor.setToGreen();
    }
    // Set color to Blue
    else if (inputColorOption == USER_OPTION_BLUE) {
        inputColor.setToBlue();
    }
    // Set color to Black
    else if (inputColorOption == USER_OPTION_BLACK) {
        inputColor.setToBlack();
    }
    // Set color to White
    else if (inputColorOption == USER_OPTION_WHITE) {
        inputColor.setToWhite();
    }
    // Invalid input
    else {
        cout << "Invalid input for color option." << endl;
        return false;
    }
    
    return true;
}