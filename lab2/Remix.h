#pragma once
#include <string>
#include "DigitalMedia.h"
#include "SoundEffect.h"

class Remix : public DigitalMedia {
public:
    Remix(const string& title, const string& recordLabel, const string& sourceUrl, 
          const string& formatDescription, const string& originalArtist, 
          const string& remixer, const string& originalSong, SoundEffect* soundEffect = nullptr);
    
    string getOriginalSong() const; 
    string getOriginalArtist() const; 
    string getRemixer() const; 
    SoundEffect* getSoundEffect() const; 
private:
    string originalSong; 
    string originalArtist; 
    string remixer; 
    SoundEffect* soundEffect; 
};