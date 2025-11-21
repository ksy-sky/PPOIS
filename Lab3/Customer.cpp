#include "Customer.h"

Customer::Customer(int uniqueCustomerId, const std::string& name, const std::string& phone, const std::string& email)
    : customerId(uniqueCustomerId), customerName(name), contactPhone(phone), contactEmail(email) {}

int Customer::getId() const { return customerId; }
const std::string& Customer::getName() const { return customerName; }
const std::string& Customer::getPhone() const { return contactPhone; }
const std::string& Customer::getEmail() const { return contactEmail; }
void Customer::addOrder(Order* orderReference) {
    customerOrders.push_back(orderReference);
}
void Customer::addReservation(Reservation* reservationReference) {
    customerReservations.push_back(reservationReference);
}
const std::vector<Order*>& Customer::getOrders() const {
    return customerOrders;
}
const std::vector<Reservation*>& Customer::getReservations() const {
    return customerReservations;
}
