#pragma once
#include "AudioDevice.h"
#include <vector>
using namespace std;
class SoundSystem : public AudioDevice {
public:
    SoundSystem(const string& model);
    string getDeviceInfo() const override;
    void addSpeaker(AudioDevice* speaker);
    int getTotalSpeakers() const;

private:
    string model;
    vector<AudioDevice*> speakers;
};