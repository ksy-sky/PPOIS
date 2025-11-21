#pragma once
#include <string>
#include <vector>
#include "DigitalMedia.h"
using namespace std;

class Podcast : public DigitalMedia {
public:
    Podcast(const string& title, const string& recordLabel, const string& sourceUrl, const string& formatDescription, const string& host);
    void addEpisode(const string& episode); 
    vector<string> getEpisodes() const; 
    string getHost() const; 
private:
    string host; 
    vector<string> episodes; 
};