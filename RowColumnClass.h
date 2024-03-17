#ifndef _ROWCOLUMNCLASS_H_
#define _ROWCOLUMNCLASS_H_

using namespace std;
#include "constants.h"

// Pixel class with row and col info
class RowColumnClass {
    public:
        // initalize inRow and inCol to -99999
        RowColumnClass(): valRow(DEFAULT_INDEX), valCol(DEFAULT_INDEX) { ;
        }; 
        // initalize inRow and inCol to given parameters
        RowColumnClass(int inRow, int inCol): valRow(inRow), 
                       valCol(inCol) { ;
        }; 

        // set inRow and inCol        
        void setRowCol(int inRow, int inCol); 
        // set inRow only        
        void setRow(int inRow); 
        // set inCol only        
        void setCol(int inCol); 
        // get the index of Row        
        int getRow(); 
        // get the index of Col       
        int getCol(); 

    private:
        int valRow;
        int valCol;
        
};

#endif