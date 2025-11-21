#include "Headphones.h"

Headphones::Headphones(const string& model, bool noiseCancellation)
    : model(model), noiseCancellation(noiseCancellation) {}

string Headphones::getDeviceInfo() const {
    return model;
}
void Headphones::toggleNoiseCancellation() {
    noiseCancellation = !noiseCancellation;
}
bool Headphones::isNoiseCancellationEnabled() const {
    return noiseCancellation;
}