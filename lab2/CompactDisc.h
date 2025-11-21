#pragma once
#include <iostream>
#include <string>
#include "PhysicalMedia.h"
using namespace std;

class CompactDisc : public PhysicalMedia {
public:
    CompactDisc(const string& title, const string& recordLabel, const AudioFormat& format, const string& condition, const string& releaseDate, int duration);
    int getDuration() const; 
private:
    int duration; 
};