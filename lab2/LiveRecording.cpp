#include "LiveRecording.h"

LiveRecording::LiveRecording(const string& artist, const string& title, const string& recordLabel, 
                           const string& sourceUrl, const string& formatDescription, 
                           const string& venue, const string& date)
    : DigitalMedia(title, recordLabel, sourceUrl, formatDescription),
      artist(artist), venue(venue), date(date) {
}
string LiveRecording::getVenue() const {
    return venue;
}
string LiveRecording::getArtist() const {
    return artist;
}
string LiveRecording::getDate() const {
    return date;
}