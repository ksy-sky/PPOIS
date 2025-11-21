#pragma once
#include <string>
using namespace std;
class Artist {
public:
    Artist(const string& name, const string& country);
    string getArtistInfo() const; 
    string getArtistName() const;
private:
    string name;
    string country; 
};