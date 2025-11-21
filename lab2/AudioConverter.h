#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "AudioFormat.h"
using namespace std;
class AudioConverter {
public:
    AudioConverter(AudioFormat& format);
    void convertFormat(const string& sourcePath, const string& targetFormat);
    string getSupportedFormats() const;
private:
    void performConversion(const string& sourcePath, const string& targetFormat);
    AudioFormat format;
    string currentSourcePath;
    string currentTargetFormat; 
};
