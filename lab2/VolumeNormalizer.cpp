#include "VolumeNormalizer.h"

VolumeNormalizer::VolumeNormalizer() : targetVolume(0.8), maxVolume(1.0) {}
void VolumeNormalizer::normalize(AudioPlayer* player) {
    double factor = calculateNormalizationFactor(player);
    cout << "Normalization of volume. Coefficient: " << factor << endl;
}
double VolumeNormalizer::calculateNormalizationFactor(AudioPlayer* player) const {
    double currentVolume = player->getVolume(); 
    if (currentVolume == 0) return 0.0f; 
    return targetVolume / currentVolume; 
}
void VolumeNormalizer::setTargetVolume(double target) {
    targetVolume = target; 
}
double VolumeNormalizer::getTargetVolume() const {
    return targetVolume; 
}
double VolumeNormalizer::getMaxVolume() const {
    return maxVolume; 
}