#include <iostream>
#include "CassetteTape.h"

CassetteTape::CassetteTape(const string& title, const string& recordLabel, const AudioFormat& format, const string& condition, 
                           const string& releaseDate, int length) 
    : PhysicalMedia(title, recordLabel, format, condition, releaseDate), length(length) {}

int CassetteTape::getLength() const {
    return length;
}