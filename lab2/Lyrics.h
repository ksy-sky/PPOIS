#pragma once
#include <iostream>
#include <string>
using namespace std;
class Lyrics {
public:
    Lyrics(const string& content);
    string getContent() const; 
private:
    string content; 
};