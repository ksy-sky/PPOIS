#include "Playlist.h"

Playlist::Playlist(const string& name, User* user) 
    : name(name), user(user) {
}
void Playlist::addSong(const Song& song) {
    songs.push_back(song);
}
void Playlist::removeSong(const string& songTitle) {
    for (auto it = songs.begin(); it != songs.end(); ) {
        if (it->getTitle() == songTitle) {
            it = songs.erase(it);
        } else {
            ++it;
        }
    }
}
void Playlist::play() const {
    cout << "Playing playlist: " << name << endl;
    for (const auto& song : songs) {
        song.play();
    }
}
vector<Song> Playlist::getSongs() const {
    return songs;
}
string Playlist::getName() const {
    return name;
}
User* Playlist::getUser() const {
    return user;
}

void Playlist::setUser(User* newUser) {
    user = newUser;
}

string Playlist::getUserUsername() const {
    if (user != nullptr) {
        return user->getUsername();
    }
    return "No owner";
}

bool Playlist::canUserModify() const {
    return user != nullptr;
}