#include "Coupon.h"

Coupon::Coupon(std::string code, double discountPercent, std::string expiry)
    : couponCode(code), discount(discountPercent), expiryDate(expiry), isActive(true) {}

bool Coupon::isValid() const { return isActive; }
void Coupon::use() { isActive = false;}
const std::string& Coupon::getCode() const { return couponCode; }
double Coupon::getDiscount() const { return discount; }
