#include "AudioQuality.h"

AudioQuality::AudioQuality(const string& qualityLevel, const string& description) 
    : qualityLevel(qualityLevel), description(description) {
}
string AudioQuality::getQualityLevel() const {
    return qualityLevel;
}
string AudioQuality::getDescription() const {
    return description;
}