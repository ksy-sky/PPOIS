#include "Podcast.h"

Podcast::Podcast(const string& title, const string& recordLabel, const string& sourceUrl, 
                 const string& formatDescription, const string& host) 
    : DigitalMedia(title, recordLabel, sourceUrl, formatDescription), host(host) { }

void Podcast::addEpisode(const string& episode) {
    episodes.push_back(episode);
}
vector<string> Podcast::getEpisodes() const {
    return episodes;
}
string Podcast::getHost() const {
    return host;
}