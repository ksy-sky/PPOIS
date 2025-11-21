#pragma once
#include <string>
using namespace std; 

class PhysicalMediaOrder {
public:
    PhysicalMediaOrder(const string& media, int quantity, const string& shippingAddress,
                  const string& status, const string& tracking,
                  bool insurance, const string& packaging,
                  const string& deliveryDate, const string& returnPolicy,
                  const string& customs, bool signature);
    void trackOrder();
    void confirmDelivery();
    void processReturn();
    double getPrice() const;
    int getQuantity() const;
    string getMedia() const;
private:
    string media; 
    int quantity; 
    string shippingAddress; 
    string status; 
    string tracking;
    bool insurance; 
    string packaging;
    string deliveryDate;
    string returnPolicy;
    string customs;
    bool signature;
};