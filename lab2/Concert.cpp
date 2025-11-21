#include "Concert.h"
#include <iostream>

Concert::Concert(const Artist& artist, const string& date, const string& venue, int ticketCount)
    : artist(artist), date(date), venue(venue), ticketCount(ticketCount), peopleCount(0) {}

void Concert::checkTickets() const {
    cout << "Concert by " << artist.getArtistName() << " on " << date << " at " 
              << venue << ". Total tickets: " << ticketCount 
              << ", People counted: " << peopleCount << endl;
}

double Concert::calculateOccupancy() const {
    if (ticketCount == 0) return 0.0f; 
    return static_cast<double>(peopleCount) / ticketCount * 100; 
}