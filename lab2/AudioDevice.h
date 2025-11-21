#pragma once
#include <string>
using namespace std;
class AudioDevice {
public:
    virtual void connect(); 
    virtual void disconnect(); 
    virtual string getDeviceInfo() const = 0; 

    virtual ~AudioDevice() = default; 
};