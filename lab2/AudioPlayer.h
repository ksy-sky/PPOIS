#pragma once
#include <string>
using namespace std;

class AudioPlayer {
public:
    AudioPlayer();
    void play();
    void pause();
    void stop();
    void setVolume(double volume);
    double getVolume() const;
private:
    string currentTrack;
    double volume; 
    bool isPlaying;
};