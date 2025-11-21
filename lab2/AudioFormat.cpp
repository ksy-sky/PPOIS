#include <iostream>
#include "AudioFormat.h"

AudioFormat::AudioFormat(const string& formatType, int sampleRate, int bitRate) 
    : formatType(formatType), sampleRate(sampleRate), bitRate(bitRate) {
}
string AudioFormat::getFormatType() const {
    return formatType;
}
int AudioFormat::getSampleRate() const {
    return sampleRate;
}
int AudioFormat::getBitRate() const {
    return bitRate;
}