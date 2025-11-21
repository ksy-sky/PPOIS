#pragma once
#include "AudioPlayer.h"
#include <iostream>
using namespace std;

class VolumeNormalizer {
public:
    VolumeNormalizer();
    void normalize(AudioPlayer* player);
    void setTargetVolume(double target); 
    double getTargetVolume() const;
    double getMaxVolume() const;
private:
    double calculateNormalizationFactor(AudioPlayer* player) const;
    double targetVolume;
    double maxVolume;
};