using namespace std;
#include "doClip.h"
#include "doClipColor.h"
#include "constants.h"

// do clipping
bool doClip(int &inRed, int &inGreen, int &inBlue) {
    // init clipping status
    bool didClip = false;

    if (doClipColor(inRed)) {
        didClip = true;
    }

    if (doClipColor(inGreen)) {
        didClip = true;
    }
    
    if (doClipColor(inBlue)) {
        didClip = true;
    }

    return didClip;
}