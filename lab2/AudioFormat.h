#pragma once
#include <iostream>
#include <string>
using namespace std;
class AudioFormat {
public:
    AudioFormat(const string& formatType, int sampleRate, int bitRate);
    string getFormatType() const; 
    int getSampleRate() const; 
    int getBitRate() const; 
private:
    string formatType; 
    int sampleRate; 
    int bitRate; 
};