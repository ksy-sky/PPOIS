#pragma once
using namespace std;
class CrossfadeManager {

public:
    CrossfadeManager();
    void setFadeDuration(double duration);
    void setEnabled(bool enabled);
    double calculateCrossfade(double currentVolume, double nextVolume, double progress) const;
    bool getIsEnabled() const;
    double getFadeDuration() const;
    void resetFade();
private:
    double fadeDuration;
    bool isEnabled;
    double currentFadeProgress;
};