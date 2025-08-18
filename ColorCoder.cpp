#include "ColorCoder.h"
#include <sstream>

namespace TelCoColorCoder {

const char* MajorColorNames[] = { "White", "Red", "Black", "Yellow", "Violet" };
int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

const char* MinorColorNames[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

ColorPair::ColorPair(MajorColor major, MinorColor minor)
    : majorColor(major), minorColor(minor) {}

MajorColor ColorPair::getMajor() const { return majorColor; }
MinorColor ColorPair::getMinor() const { return minorColor; }

std::string ColorPair::ToString() const {
    return std::string(MajorColorNames[majorColor]) + " " + MinorColorNames[minorColor];
}

ColorPair GetColorFromPairNumber(int pairNumber) {
    int zeroBased = pairNumber - 1;
    MajorColor major = (MajorColor)(zeroBased / numberOfMinorColors);
    MinorColor minor = (MinorColor)(zeroBased % numberOfMinorColors);
    return ColorPair(major, minor);
}

int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
    return major * numberOfMinorColors + minor + 1;
}

std::string GetColorCodeReference() {
    std::ostringstream oss;
    for (int major = 0; major < numberOfMajorColors; major++) {
        for (int minor = 0; minor < numberOfMinorColors; minor++) {
            int pairNumber = GetPairNumberFromColor((MajorColor)major, (MinorColor)minor);
            oss << pairNumber << "\t" << MajorColorNames[major] 
                << "\t" << MinorColorNames[minor] << "\n";
        }
    }
    return oss.str();
}
}
