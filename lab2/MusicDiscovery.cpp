#include "MusicDiscovery.h"
#include <iostream>

void MusicDiscovery::searchByGenre(const string& genre) {
    cout << "Searching music by genre: " << genre << endl;
}
void MusicDiscovery::advancedSearch(const vector<string>& criteria) {
    cout << "Performing advanced search with criteria." << endl;
    this->criteria = criteria;
}
void MusicDiscovery::saveSearch(const string& searchName) {
    savedSearches.push_back(searchName);
    cout << "Saved search: " << searchName << endl;
}