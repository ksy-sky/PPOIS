#include "AudioConverter.h"
#include <iostream>

AudioConverter::AudioConverter(AudioFormat& format)
    : format(format) { // Инициализация поддерживаемых форматов
}
void AudioConverter::convertFormat(const string& sourcePath, const string& targetFormat) {
    performConversion(sourcePath, targetFormat);
}
string AudioConverter::getSupportedFormats() const {
    return "mp3, wav, flac";
}
void AudioConverter::performConversion(const string& sourcePath, const string& targetFormat) {
    cout << "Converting " << sourcePath << " to format " << targetFormat << endl;
}