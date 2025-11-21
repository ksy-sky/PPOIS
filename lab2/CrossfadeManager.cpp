#include "CrossfadeManager.h"
#include <algorithm>

CrossfadeManager::CrossfadeManager() 
    : fadeDuration(3.0), isEnabled(true), currentFadeProgress(0.0) {}

void CrossfadeManager::setFadeDuration(double duration) {
    fadeDuration = duration; 
}
void CrossfadeManager::setEnabled(bool enabled) {
    isEnabled = enabled;
}
double CrossfadeManager::calculateCrossfade(double currentVolume, double nextVolume, double progress) const {
     if (!isEnabled) return currentVolume;
    
    double fadeProgress = progress / fadeDuration;
    if (fadeProgress > 1.0) fadeProgress = 1.0;
    return currentVolume * (1.0 - fadeProgress) + nextVolume * fadeProgress;
}
bool CrossfadeManager::getIsEnabled() const {
    return isEnabled;
}
double CrossfadeManager::getFadeDuration() const {
    return fadeDuration;
}
void CrossfadeManager::resetFade() {
    currentFadeProgress = 0.0;
}