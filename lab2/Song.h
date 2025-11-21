#pragma once
#include <string>
#include "Artist.h"
#include "Genre.h"
#include "Lyrics.h"
using namespace std;
class Song {
public:
    Song(const string& title, const Artist& artist, int duration, const Genre& genre, const Lyrics& lyrics);
    void play() const;
    string getInfo() const;
    void setLyrics(const string& lyrics);
    string getLyrics() const;
    string getArtistName() const;
    string getTitle() const;
private:
    string title;
    Artist artist;
    int duration;
    Genre genre;
    Lyrics lyrics;
};