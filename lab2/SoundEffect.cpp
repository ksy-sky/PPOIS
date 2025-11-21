#include<iostream>
#include "SoundEffect.h"

SoundEffect::SoundEffect(const string& name, const string& category, double duration, const string& format,
                const string& application, const string& author, double price,
                const vector<string>& tags, const vector<double>& parameters, const string& usageRights)
        : name(name), category(category), duration(duration), format(format), application(application),
          author(author), price(price), tags(tags), parameters(parameters), usageRights(usageRights) {}

void SoundEffect::preview() const {
    cout << "Previewing sound effect: " << name << " (" << category << ")" << endl;
}
void SoundEffect::applyToAudio() const {
    cout << "Applying sound effect: " << name << " to audio." << endl;
}
void SoundEffect::categorize() const {
    cout << "Categorizing sound effect: " << name << " under " << category << "." << endl;
}