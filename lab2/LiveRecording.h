#pragma once
#include <string>
#include "DigitalMedia.h"
using namespace std;

class LiveRecording : public DigitalMedia {
public:
    LiveRecording(const string& artist, const string& title, const string& recordLabel, const string& sourceUrl, 
                  const string& formatDescription, const string& venue, const string& date);
    
    string getVenue() const; 
    string getDate() const; 
    string getArtist() const; 
private:
    string venue;
    string date; 
    string artist; 
};