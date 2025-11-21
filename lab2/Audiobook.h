#pragma once
#include <string>
#include "DigitalMedia.h"
using namespace std;

class Audiobook : public DigitalMedia {
public:
    Audiobook(const string& title, const string& recordLabel, const string& sourceUrl, 
              const string& formatDescription, const string& author, int duration, const string& narrator, int chapters);
    
    string getAuthor() const; // Возвращает имя автора
    string getNarrator() const; // Возвращает имя исполнителя
    int getDuration() const; // Возвращает продолжительность в минутах
    int getChapters() const; // Возвращает количество глав
private:
    string author; // Имя автора
    string narrator; // Исполнитель аудиокниги
    int chapters; // Количество глав
    int duration; // Продолжительность в минутах
};