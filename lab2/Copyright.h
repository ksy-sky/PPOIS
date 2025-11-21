#pragma once
#include <string>
#include <vector>
using namespace std;
class Copyright {
public:
    Copyright(const string& owner, const string& date);
    string getOwner() const; 
    string getDate() const; 
    void addRestrictedCountry(const string& country); 
    vector<string> getRestrictedCountries() const; 
private:
    string owner;
    string date; 
    vector<string> restrictedCountries;
};