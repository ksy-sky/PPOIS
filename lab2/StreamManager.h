#pragma once
#include <iostream>
#include <string>
using namespace std;

class StreamManager {
public:
    StreamManager();
    void startStream(const string& url); 
    void stopStream(); 
    bool isStreaming() const;
private:
    bool streaming;
};
