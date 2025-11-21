#include "WirelessSpeaker.h"

WirelessSpeaker::WirelessSpeaker(const string& model, int batteryLife)
    : model(model), batteryLife(batteryLife), batteryLevel(100) {}

string WirelessSpeaker::getDeviceInfo() const {
    return model;
}
void WirelessSpeaker::setBatteryLevel(int level) {
    batteryLevel = level;
}
int WirelessSpeaker::getBatteryLevel() const {
    return batteryLevel;
}