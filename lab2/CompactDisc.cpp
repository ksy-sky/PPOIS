#include "CompactDisc.h"

CompactDisc::CompactDisc(const string& title, const string& recordLabel, const AudioFormat& format, const string& condition, 
       const string& releaseDate, int duration) 
    : PhysicalMedia(title, recordLabel, format, condition, releaseDate), duration(duration) {}

int CompactDisc::getDuration() const {
    return duration;
}