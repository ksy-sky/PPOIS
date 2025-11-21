#include "Song.h"
#include <iostream>

Song::Song(const string& title, const Artist& artist, int duration, const Genre& genre, const Lyrics& lyrics) 
    : title(title), artist(artist), duration(duration), genre(genre), lyrics(lyrics) {
}
void Song::play() const {
    cout << "Playing: " << title << " by " << artist.getArtistInfo() << std::endl;
}
string Song::getInfo() const {
    return "Title: " + title + "\nArtist: " + artist.getArtistInfo() + "\nDuration: " + to_string(duration) + " seconds\nGenre: " + genre.getName();
}
void Song::setLyrics(const string& lyrics) {
    this->lyrics = lyrics;
}
string Song::getLyrics() const {
    return lyrics.getContent();
}
string Song::getTitle() const {
    return title;
}
string Song::getArtistName() const {
    return artist.getArtistName();
}