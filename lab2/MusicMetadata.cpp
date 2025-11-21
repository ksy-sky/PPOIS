#include "MusicMetadata.h"
#include <iostream>

// Конструктор создает пустые объекты ассоциаций
MusicMetadata::MusicMetadata(int bpm, const string& key, const string& mood, double energy,
                           double danceability, double acoustics, const vector<string>& instruments,
                           const string& era, const string& style, const string& language,
                           const string& recordingLocation, const string& technicalData)
    : bpm(bpm), key(key), mood(mood), energy(energy), danceability(danceability),
      acoustics(acoustics), instruments(instruments), era(era), style(style),
      language(language), recordingLocation(recordingLocation), technicalData(technicalData),
      song(Song("", Artist("Unknown", ""), 0, Genre(""), Lyrics(""))),
      copyright(Copyright("Unknown", "2024")),
      quality(AudioQuality("Standard", "Default")) {}


void MusicMetadata::extractMetadata() const {
    // Используем данные из ассоциаций
    cout << "Extracting metadata for: " << song.getTitle() << endl;
    cout << "Artist: " << song.getArtistName() << endl;
    cout << "Audio Quality: " << quality.getQualityLevel() << endl;
    cout << "Copyright: " << copyright.getOwner() << endl;
    cout << "BPM: " << bpm << ", Key: " << key << endl;
}

void MusicMetadata::analyzeStyle() const {
    cout << "Analyzing style for: " << song.getTitle() << endl;
    cout << "Genre: " << style << ", Era: " << era << endl;
    cout << "Mood: " << mood << ", Energy: " << energy << endl;
}

bool MusicMetadata::validate() const {
    if (bpm <= 0 || bpm > 300) return false;
    if (energy < 0.0 || energy > 1.0) return false;
    if (danceability < 0.0 || danceability > 1.0) return false;
    if (acoustics < 0.0 || acoustics > 1.0) return false;
    
    return true;
}

Song& MusicMetadata::getSong() {
    return song;
}

Copyright& MusicMetadata::getCopyright() {
    return copyright;
}

AudioQuality& MusicMetadata::getAudioQuality() {
    return quality;
}

void MusicMetadata::setSong(const Song& newSong) {
    song = newSong;
}

void MusicMetadata::setCopyright(const Copyright& newCopyright) {
    copyright = newCopyright;
}

void MusicMetadata::setAudioQuality(const AudioQuality& newQuality) {
    quality = newQuality;
}