#include "ListeningHistory.h"

void ListeningHistory::addSong(const Song& song) {
    songs.push_back(song); 
}
void ListeningHistory::clearHistory() {
    songs.clear(); }
vector<Song> ListeningHistory::getHistory() const {
    return songs; 
}