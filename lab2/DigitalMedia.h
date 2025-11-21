#pragma once
#include <string>
#include <vector>
using namespace std;

class DigitalMedia {
public:
    DigitalMedia(const string& title, const string& recordLabel, const string& sourceUrl, const string& formatDescription);
    string getTitle() const; 
    string getRecordLabel() const; 
    string getSourceUrl() const; 
    string getFormatDescription() const; 
protected:
    string title;
    string recordLabel; 
    string sourceUrl;
    string formatDescription;
};