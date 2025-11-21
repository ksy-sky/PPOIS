#pragma once
#include <string>
using namespace std;
class AudioQuality {
public:
    AudioQuality(const string& qualityLevel, const string& description);
    string getQualityLevel() const; 
    string getDescription() const; 
private:
    string qualityLevel; 
    string description; 
};