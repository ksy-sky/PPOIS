#pragma once
#include <string>
#include <vector>
#include "Song.h"
#include "Copyright.h"
#include "AudioQuality.h"
using namespace std;

class MusicMetadata {
public:
    MusicMetadata(int bpm, const string& key, const string& mood, double energy,
                  double danceability, double acoustics, const vector<string>& instruments,
                  const string& era, const string& style, const string& language,
                  const string& recordingLocation, const string& technicalData);
    void extractMetadata() const;
    void analyzeStyle() const;
    bool validate() const;
    Song& getSong();
    Copyright& getCopyright();
    AudioQuality& getAudioQuality();
    void setSong(const Song& newSong);
    void setCopyright(const Copyright& newCopyright);
    void setAudioQuality(const AudioQuality& newQuality);

private:
    int bpm;                             
    string key; 
    string mood;       
    double energy;  
    double danceability;
    double acoustics;   
    vector<string> instruments; 
    string era;  
    string style;     
    string language;
    string recordingLocation;  
    string technicalData;   
    Song song;  
    Copyright copyright;
    AudioQuality quality; 
};