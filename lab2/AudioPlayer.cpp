#include <iostream>
#include "AudioPlayer.h"
using namespace std;

AudioPlayer::AudioPlayer()
    : volume(1.0f), isPlaying(false), currentTrack("") {
}
void AudioPlayer::play() {
        isPlaying = true;
}
void AudioPlayer::pause() {
        isPlaying = false;
}
void AudioPlayer::stop() {
        isPlaying = false;
}
void AudioPlayer::setVolume(double newVolume) {
   if (newVolume < 0.0) {
        volume = 0.0;
    } else if (newVolume > 1.0) {
        volume = 1.0;
    } else {
        volume = newVolume;
    }
}
double AudioPlayer::getVolume() const {
    return volume; 
}
