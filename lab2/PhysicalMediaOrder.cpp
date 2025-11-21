#include "PhysicalMediaOrder.h"
#include <iostream>

PhysicalMediaOrder::PhysicalMediaOrder(const string& media, int quantity, const string& shippingAddress,
                              const string& status, const string& tracking,
                              bool insurance, const string& packaging,
                              const string& deliveryDate, const string& returnPolicy,
                              const string& customs, bool signature)
    : media(media), quantity(quantity), shippingAddress(shippingAddress), status(status),
      tracking(tracking), insurance(insurance), packaging(packaging),
      deliveryDate(deliveryDate), returnPolicy(returnPolicy), customs(customs), signature(signature) {}

void PhysicalMediaOrder::trackOrder() {
    cout << "Tracking order: " << tracking << endl;
}
void PhysicalMediaOrder::confirmDelivery() {
    status = "Delivered";
    cout << "Delivery confirmed for " << media << endl;
}
void PhysicalMediaOrder::processReturn() {
    cout << "Processing return for " << media << " under policy: " << returnPolicy << endl;
}
double PhysicalMediaOrder::getPrice() const {
    return 15.99;
}
int PhysicalMediaOrder::getQuantity() const {
    return quantity;
}
string PhysicalMediaOrder::getMedia() const {
    return media;
}