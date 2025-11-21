#include "DigitalPurchase.h"
#include <iostream>

DigitalPurchase::DigitalPurchase(const string& item, const string& purchaseDate, double price,
                                   const string& license, const string& downloadLink,
                                   const string& restrictions, const string& refundPolicy, bool ownership)
    : item(item), purchaseDate(purchaseDate), price(price), license(license),
      downloadLink(downloadLink), restrictions(restrictions), refundPolicy(refundPolicy), ownership(ownership) {}

void DigitalPurchase::activateLicense() {
    if (ownership) {
        cout << "License for " << item << " activated." << endl;
    } else {
        cout << "You do not own a license for " << item << "." << endl;
    }
}
void DigitalPurchase::download() {
    if (ownership) {
        cout << "Downloading " << item << " from " << downloadLink << endl;
    } else {
        cout << "You do not own " << item << "." << endl;
    }
}
void DigitalPurchase::requestRefund() {
    cout << "Refund requested for " << item << " under policy: " << refundPolicy << endl;
}
string DigitalPurchase::getItem() const {
    return item;
}
double DigitalPurchase::getPrice() const {
    return price;
}