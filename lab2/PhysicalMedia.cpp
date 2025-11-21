#include <iostream>
#include "PhysicalMedia.h"

PhysicalMedia::PhysicalMedia(const string& title, const string& recordLabel, const AudioFormat& format, const string& condition, const string& releaseDate)
    : title(title), recordLabel(recordLabel), format(format), condition(condition), releaseDate(releaseDate) {
}
string PhysicalMedia::getTitle() const {
    return title;
}
string PhysicalMedia::getRecordLabel() const {
    return recordLabel;
}
AudioFormat PhysicalMedia::getFormat() const {
    return format;
}
string PhysicalMedia::getCondition() const {
    return condition;
}
string PhysicalMedia::getReleaseDate() const {
    return releaseDate;
}