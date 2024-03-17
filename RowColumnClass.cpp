#include <iostream>
using namespace std;
#include "RowColumnClass.h"
#include "constants.h"

// set inRow and inCol        
void RowColumnClass::setRowCol(int inRow, int inCol) {
    valRow = inRow;
    valCol = inCol;
}

// set inRow only     
void RowColumnClass::setRow(int inRow) {
    valRow = inRow;
}

// set inCow only     
void RowColumnClass::setCol(int inCol) {
    valCol = inCol;
}

// get the index of Row 
int RowColumnClass::getRow() {
    return valRow;
}

// get the index of Col 
int RowColumnClass::getCol() {
    return valCol;
}

