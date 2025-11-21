#include <iostream>
#include "Lyrics.h"
Lyrics::Lyrics(const string& content) 
    : content(content) {
}
string Lyrics::getContent() const {
    return content;
}