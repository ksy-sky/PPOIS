#pragma once
#include <string>
using namespace std;
class DigitalPurchase {
public:
    DigitalPurchase(const string& item, const string& purchaseDate, double price,
                    const string& license, const string& downloadLink,
                    const string& restrictions, const string& refundPolicy, bool ownership);
    void activateLicense();
    void download();
    void requestRefund();
    string getItem() const;
    double getPrice() const;

private:
    string item; 
    string purchaseDate; 
    double price; 
    string license; 
    string downloadLink; 
    string restrictions; 
    string refundPolicy;
    bool ownership; 
};