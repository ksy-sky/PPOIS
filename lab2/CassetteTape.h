#pragma once
#include <iostream>
#include <string>
#include "PhysicalMedia.h"
using namespace std;

class CassetteTape : public PhysicalMedia {
public:
    CassetteTape(const string& title, const string& recordLabel, const AudioFormat& format, const string& condition, 
                 const string& releaseDate, int length);
    
    int getLength() const; 
private:
    int length;
};