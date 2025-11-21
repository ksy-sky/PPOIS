#include "SoundSystem.h"

SoundSystem::SoundSystem(const string& model) : model(model) {}

string SoundSystem::getDeviceInfo() const {
    return model;
}
void SoundSystem::addSpeaker(AudioDevice* speaker) {
    speakers.push_back(speaker);
}
int SoundSystem::getTotalSpeakers() const {
    return speakers.size();
}