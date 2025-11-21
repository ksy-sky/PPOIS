#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Song.h"
#include "User.h"
using namespace std;
class Playlist {
public:
    Playlist(const string& name, User* user = nullptr);
    void addSong(const Song& song); 
    void removeSong(const string& songTitle); 
    void play() const; 
    vector<Song> getSongs() const; 
    string getName() const; 
    User* getUser() const;
    void setUser(User* newUser);
    string getUserUsername() const;
    bool canUserModify() const;
private:
    string name; 
    vector<Song> songs;
    User* user;
};