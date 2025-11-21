#include "Equalizer.h"

Equalizer::Equalizer() {
    bandGains.fill(0.0f); 
}
void Equalizer::setBandGain(int band, double gain) {
    if (band >= 0 && band < bandGains.size()) {
        bandGains[band] = gain;
    }
}
void Equalizer::apply(AudioPlayer* player) {
    if (!player) return;
    double overallGain = 1.0;
    for (int i = 0; i < 10; i++) {
        overallGain += bandGains[i] * 0.1;
    }
    
    player->setVolume(overallGain);
}