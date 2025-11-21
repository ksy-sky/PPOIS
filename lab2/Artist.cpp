#include "Artist.h"

Artist::Artist(const string& name, const string& country) 
    : name(name), country(country) {
}
string Artist::getArtistName() const{
    return name;
}
string Artist::getArtistInfo() const {
    return name + " from " + country;
}