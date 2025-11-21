#pragma once
#include<iostream>
#include <string>
#include "Artist.h"
using namespace std;
class Concert {
public:
    Concert(const Artist& artist, const string& date, const string& venue, int ticketCount);
    void checkTickets() const;
    double calculateOccupancy() const;
private:
    Artist artist; 
    string date; 
    string venue; 
    int ticketCount; 
    int peopleCount;      
};