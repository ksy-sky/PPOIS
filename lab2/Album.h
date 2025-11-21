#pragma once
#include <string>
#include <vector>
#include "Song.h"
#include "Artist.h"
using namespace std;
class Album {
public:
    Album(const string& title, const Artist& artist);
    void addSong(const Song& song); 
    vector<Song> getSongs() const; 
    string getAlbumInfo() const;
    string getTitle() const;
    string getArtistName() const;
private:
    string title; 
    Artist artist; 
    vector<Song> songs; 
};