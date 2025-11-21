#include "StreamManager.h"
#include <iostream>

StreamManager::StreamManager() 
    : streaming(false) {
}
void StreamManager::startStream(const string& url) {
    streaming = true;
    cout << "Starting stream from: " << url << endl;
}
void StreamManager::stopStream() {
    streaming = false;
    cout << "Stream stopped." << endl;
}
bool StreamManager::isStreaming() const {
    return streaming;
}