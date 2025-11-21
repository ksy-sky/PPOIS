#include <iostream>
#include "VinylRecord.h"

VinylRecord::VinylRecord(const string& title, const string& recordLabel, const AudioFormat& format, const string& condition, 
                         const string& releaseDate, int diameter) 
    : PhysicalMedia(title, recordLabel, format, condition, releaseDate), diameter(diameter) {}

int VinylRecord::getDiameter() const {
    return diameter;
}