#include "MusicVideo.h"

MusicVideo::MusicVideo(const string& title, const string& recordLabel, const string& sourceUrl, 
                       const string& formatDescription, const string& artist, int duration, const string& director) 
    : DigitalMedia(title, recordLabel, sourceUrl, formatDescription), artist(artist), duration(duration), director(director) {}

string MusicVideo::getArtist() const {
    return artist;
}
int MusicVideo::getDuration() const {
    return duration;
}
string MusicVideo::getDirector() const {
    return director;
}