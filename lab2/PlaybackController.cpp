#include "PlaybackController.h"

void PlaybackController::addPlayer(AudioPlayer* player) {
    players.push_back(player);
}
void PlaybackController::removePlayer(AudioPlayer* player) {
    for (auto it = players.begin(); it != players.end(); ++it) {
        if (*it == player) {
            players.erase(it);
            break; 
        }
    }
}
void PlaybackController::startAll() {
    for (auto player : players) {
        player->play();
    }
}
void PlaybackController::stopAll() {
    for (auto player : players) {
        player->stop();
    }
}