#pragma once
#include <vector>
#include "AudioPlayer.h"
using namespace std;

class PlaybackController {
public:
    PlaybackController() = default;
    void addPlayer(AudioPlayer* player);
    void removePlayer(AudioPlayer* player);
    void startAll();
    void stopAll();
private:
    vector<AudioPlayer*> players; 
};