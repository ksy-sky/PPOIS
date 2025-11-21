#pragma once
#include <iostream>
#include <string>
using namespace std;
class Genre {
public:
    Genre(const string& name);
    string getName() const; 
    void setName(const string& name); 
private:
    string name; 
};