#pragma once
#include "AudioDevice.h"
using namespace std;
class WirelessSpeaker : public AudioDevice {
public:
    WirelessSpeaker(const string& model, int batteryLife);
    string getDeviceInfo() const override;
    void setBatteryLevel(int level);
    int getBatteryLevel() const;
private:
    string model;
    int batteryLife;
    int batteryLevel;
};