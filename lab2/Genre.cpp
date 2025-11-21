#include "Genre.h"
#include <iostream>

Genre::Genre(const string& name) 
    : name(name) {
}
string Genre::getName() const {
    return name;
}
void Genre::setName(const string& name) {
    this->name = name;
}