#include "DigitalMedia.h"

DigitalMedia::DigitalMedia(const string& title, const string& recordLabel, const string& sourceUrl, const string& formatDescription)
    : title(title), recordLabel(recordLabel), sourceUrl(sourceUrl), formatDescription(formatDescription) {}

    string DigitalMedia::getTitle() const {
    return title;
}
string DigitalMedia::getRecordLabel() const {
    return recordLabel;
}
string DigitalMedia::getSourceUrl() const {
    return sourceUrl;
}
string DigitalMedia::getFormatDescription() const {
    return formatDescription;
}