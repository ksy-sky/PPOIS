#include "Audiobook.h"

Audiobook::Audiobook(const string& title, const string& recordLabel, const string& sourceUrl, 
              const string& formatDescription, const string& author, int duration, const string& narrator, int chapters)
    : DigitalMedia(title, recordLabel, sourceUrl, formatDescription),
      author(author), narrator(narrator), chapters(chapters), duration(duration) {
}
string Audiobook::getAuthor() const {
    return author;
}
string Audiobook::getNarrator() const {
    return narrator;
}
int Audiobook::getDuration() const {
    return duration;
}
int Audiobook::getChapters() const {
    return chapters;
}