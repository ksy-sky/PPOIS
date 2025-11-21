#pragma once
#include <array>
#include "AudioPlayer.h"
using namespace std;

class Equalizer {
public:
    Equalizer();
    void setBandGain(int band, double gain); 
    void apply(AudioPlayer* player); 
private:
    array<double, 10> bandGains; 
};