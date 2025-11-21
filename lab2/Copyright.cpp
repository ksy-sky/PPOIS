#include "Copyright.h"

Copyright::Copyright(const string& owner, const string& date) 
    : owner(owner), date(date) {
}

std::string Copyright::getOwner() const {
    return owner;
}
std::string Copyright::getDate() const {
    return date;
}
void Copyright::addRestrictedCountry(const string& country) {
    restrictedCountries.push_back(country);
}

vector<string> Copyright::getRestrictedCountries() const {
    return restrictedCountries;
}