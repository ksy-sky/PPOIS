#pragma once
#include <string>

class Coupon {
public:
    Coupon(std::string code, double discountPercent, std::string expiry);
    bool isValid() const;
    void use();
    const std::string& getCode() const;
    double getDiscount() const;
private:
    std::string couponCode;
    double discount; 
    std::string expiryDate;
    bool isActive;
};
