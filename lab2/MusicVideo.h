#pragma once
#include <string>
#include "DigitalMedia.h"
using namespace std;

class MusicVideo : public DigitalMedia {
public:
    MusicVideo(const string& title, const string& recordLabel, const string& sourceUrl, 
               const string& formatDescription, const string& artist, int duration, const string& director);
    
    string getArtist() const;
    int getDuration() const; 
    string getDirector() const; 
private:
    string artist; 
    int duration; 
    string director; 
};