#include <iostream>
using namespace std;
#include "RowColumnClass.h"

// ask for insert index based on mode
bool askForInsertIdx(RowColumnClass &insertIdx, int mode) {
    // insert index of pattern
    int insertRow, insertCol;

    if (mode == USER_CHOICE_ANNOTATE_PATTERN) {
        cout << "Enter upper left corner of pattern row and column: "; 
    }
    else if (mode == USER_CHOICE_INSERT_IMAGE) {
        cout << "Enter upper left corner to insert image row and column: ";
    }

    cin >> insertRow >> insertCol;
    // check bad input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(MAX_INT, NEW_LINE_CHAR);
        cout << "Fail to input row and col" << endl;
        return false;
    }
    
    insertIdx.setRowCol(insertRow, insertCol);
    
    return true;
}