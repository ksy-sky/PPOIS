#include "MusicStore.h"
#include <iostream>
#include <algorithm>

MusicStore::MusicStore()
    : sales(0.0f), inventory(0), taxes(0.0f) {}

void MusicStore::searchCatalog(const string& query) {
    cout << "Searching catalog for: " << query << endl;
    bool found = false;
    
    for (const auto& song : catalog) {
        if (song.getTitle().find(query) != string::npos || song.getArtistName().find(query) != string::npos) {
            cout << "Found: " << song.getTitle() << " by " << song.getArtistName() << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No results found for: " << query << endl;
    }
}
void MusicStore::processSale(const DigitalPurchase& purchase) {
    sales += purchase.getPrice();
    cout << "Processed digital sale: " << purchase.getItem() << " for $" << purchase.getPrice() << endl;
    updateInventory(purchase.getItem(), -1); // Decrement stock
}
void MusicStore::processSale(const PhysicalMediaOrder& order) {
    sales += order.getPrice() * order.getQuantity();
    cout << "Processed physical media sale: " << order.getMedia() << " for $" << order.getPrice() << " x " << order.getQuantity() << endl;
    updateInventory(order.getMedia(), -order.getQuantity()); // Decrement stock
}

void MusicStore::updateInventory(const string& mediaTitle, int quantity) {
    cout << "Updating inventory for " << mediaTitle << " by " << quantity << endl;
    inventory += quantity;
}