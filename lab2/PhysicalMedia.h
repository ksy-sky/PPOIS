#pragma once
#include <iostream>
#include <string>
#include "AudioFormat.h"
using namespace std;

class PhysicalMedia {
public:
    PhysicalMedia(const string& title, const string& recordLabel, const AudioFormat& format, const string& condition, const string& releaseDate);
    string getTitle() const; 
    string getRecordLabel() const; 
    AudioFormat getFormat() const; 
    string getCondition() const; 
    string getReleaseDate() const; 
protected:
    string title; 
    string recordLabel; 
    AudioFormat format;
    string condition;
    string releaseDate; 
};