#include "DownloadManager.h"
#include <iostream>

DownloadManager::DownloadManager(User* user) : user(user), progress(0.0), speed(0.0), limit(5.0) {}

void DownloadManager::downloadTrack(const Song& song) {
    if (downloadQueue.size() >= limit) {
        cout << "Download limit reached. Cannot add " << song.getTitle() << " by " << song.getArtistName() << "." << endl;
        return;
    }
    downloadQueue.push_back(song);
    user->addDownload(song.getTitle()); 
    cout << "Added track to download queue: " << song.getTitle() << " by " << song.getArtistName() << endl;
}
void DownloadManager::pause() {
    cout << "Pausing all downloads." << endl;
}
void DownloadManager::resume() {
    cout << "Resuming downloads." << endl;
}
bool DownloadManager::checkLimit() const {
    if (downloadQueue.size() >= limit) {
        cout << "You have reached your download limit: " << limit << endl;
        return false;
    }
    cout << "You can download more tracks." << endl;
    return true;
}