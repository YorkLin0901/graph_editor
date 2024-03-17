#ifndef _CONSTANTS_H
#define _CONSTANTS_H

#include <string>
using namespace std;

// max int for ciin.ignore
const int MAX_INT = 200;
const char NEW_LINE_CHAR = '\n';

// max value for a RGB color
const int MAX_COLOR_VALUE = 255; 
// min value for a RGB color
const int MIN_COLOR_VALUE = 0; 
// default index for RowColumnClass
const int DEFAULT_INDEX = -99999; 
// the ppm magic number used in this project 
const string MAGIC_NUM_SETTING = "P3"; 

// Option: Annotate image with rectangle
const int USER_CHOICE_ANNOTATE_RECTANGLE = 1;
// Option: Annotate image with pattern from file
const int USER_CHOICE_ANNOTATE_PATTERN = 2;
// Option: Insert another image
const int USER_CHOICE_INSERT_IMAGE = 3;
// Option: Write out current image
const int USER_CHOICE_WRITE_OUT = 4;
// Option: Exit the program
const int USER_CHOICE_EXIT = 5;

// Option: Specify upper left and lower right corners of rectangle
const int USER_CHOICE_RECTANGLE_TWO_CORNER = 1;
// Option: Specify upper left corner and dimensions of rectangle
const int USER_CHOICE_RECTANGLE_CORNER_DIM = 2;
// Option: Specify extent from center of rectangle
const int USER_CHOICE_RECTANGLE_CENTER_DIM = 3;

// Option for Red
const int USER_OPTION_RED = 1;
// Option for Green
const int USER_OPTION_GREEN = 2;
// Option for Blue
const int USER_OPTION_BLUE = 3;
// Option for Black
const int USER_OPTION_BLACK = 4;
// Option for White
const int USER_OPTION_WHITE = 5;

// Option for non-filled rectangle
const int USER_CHOICE_NON_FILLED_RECTANGLE = 1;
// Option for filled rectangle
const int USER_CHOICE_FILLED_RECTANGLE = 2;

// Transparent binary value in pattern
const int PATTERN_NONE_VALUE = 0;
// Filled binary value in pattern
const int PATTERN_FILLED_VALUE = 1;

// index adjustment for 0-base index and 1-base index
const int IDX_ADJUST = 1;

#endif
