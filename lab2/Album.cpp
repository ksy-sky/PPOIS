#include "Album.h"

Album::Album(const string& title, const Artist& artist) 
    : title(title), artist(artist) {}

void Album::addSong(const Song& song) {
    songs.push_back(song);
}
vector<Song> Album::getSongs() const {
    return songs;
}
string Album::getAlbumInfo() const {
    return "Album: " + title + "\nArtist: " + artist.getArtistName() + "\nSongs: " + to_string(songs.size());
}
string Album::getTitle() const {
    return title;
}
string Album::getArtistName() const {
    return artist.getArtistName();
}