#pragma once
#include <string>
#include <vector>
#include "Order.h"
#include "Reservation.h"

class Customer {
public:
    Customer(int uniqueCustomerId, const std::string& name, const std::string& phone, const std::string& email);
    int getId() const;
    const std::string& getName() const;
    const std::string& getPhone() const;
    const std::string& getEmail() const;
    void addOrder(Order* orderReference);
    void addReservation(Reservation* reservationReference);
    const std::vector<Order*>& getOrders() const;
    const std::vector<Reservation*>& getReservations() const;
private:
    int customerId;
    std::string customerName;
    std::string contactPhone;
    std::string contactEmail;
    std::vector<Order*> customerOrders;
    std::vector<Reservation*> customerReservations;
};
