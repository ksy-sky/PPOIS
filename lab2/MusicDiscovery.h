#pragma once
#include<iostream>
#include <vector>
#include <string>
using namespace std;

class MusicDiscovery {
public:
    MusicDiscovery() = default;
    void searchByGenre(const string& genre);
    void advancedSearch(const vector<string>& criteria);
    void saveSearch(const string& searchName);

private:
    vector<string> searchFilters; 
    vector<string> criteria; 
    vector<string> results; 
    vector<string> history; 
    vector<string> savedSearches; 
    vector<string> trends; 
    vector<string> filters; 
    vector<string> advancedOptions; 
};