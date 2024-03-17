using namespace std;
#include "doClipColor.h"
#include "constants.h"

// clip single color
bool doClipColor(int &colorValue) {
    bool didClip = false;

    if (colorValue < MIN_COLOR_VALUE) {
        colorValue = MIN_COLOR_VALUE;
        didClip = true;
    }
    else if (colorValue > MAX_COLOR_VALUE) {
        colorValue = MAX_COLOR_VALUE;
        didClip = true;
    }
    
    return didClip;
}
