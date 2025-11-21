#pragma once
#include <string>
#include <vector>
#include "User.h"
#include "Song.h"
#include "DigitalPurchase.h"
#include "PhysicalMediaOrder.h"
using namespace std;

class MusicStore {
public:
    MusicStore();
    void searchCatalog(const string& query);
    void processSale(const DigitalPurchase& purchase);
    void processSale(const PhysicalMediaOrder& order);
    void updateInventory(const string& mediaTitle, int quantity);

private:
    vector<Song> catalog; 
    vector<User> users; 
    double sales; 
    int inventory; 
    vector<string> promotions; 
    vector<double> ratings; 
    vector<string> suppliers; 
    string policies; 
    vector<string> statistics; 
    vector<string> regions; 
    double taxes; 
    string shipping; 
};