#pragma once
#include <string>
#include "PhysicalMedia.h"
using namespace std;

class VinylRecord : public PhysicalMedia {
public:
    VinylRecord(const string& title, const string& recordLabel, const AudioFormat& format,
         const string& condition, const string& releaseDate, int diameter);
    
    int getDiameter() const; 
private:
    int diameter; 
};