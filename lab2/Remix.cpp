#include "Remix.h"

Remix::Remix(const string& title, const string& recordLabel, const string& sourceUrl, 
             const string& formatDescription, const string& originalArtist, const string& remixer, const string& originalSong, SoundEffect* soundEffect) 
    : DigitalMedia(title, recordLabel, sourceUrl, formatDescription), originalArtist(originalArtist), remixer(remixer), originalSong(originalSong), soundEffect (soundEffect) {}

string Remix::getOriginalArtist() const {
    return originalArtist;
}
string Remix::getRemixer() const {
    return remixer;
}
string Remix::getOriginalSong() const {
    return originalSong;
}
SoundEffect* Remix::getSoundEffect() const {
    return soundEffect; 
}