#pragma once
#include "AudioDevice.h"
using namespace std;
class Headphones : public AudioDevice {
public:
    Headphones(const string& model, bool noiseCancellation);
    string getDeviceInfo() const override;
    void toggleNoiseCancellation();
    bool isNoiseCancellationEnabled() const;

private:
    string model;
    bool noiseCancellation;
};