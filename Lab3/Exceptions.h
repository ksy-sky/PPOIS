#pragma once
#include <exception>
#include <string>

class BaseException : public std::exception {
protected:
    std::string message;
public:
    explicit BaseException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};
class OrderCreationException : public BaseException {
public:
    explicit OrderCreationException(const std::string& msg) : BaseException("Order Creation Error: " + msg) {}
};
class OrderItemException : public BaseException {
public:
    explicit OrderItemException(const std::string& msg) : BaseException("Order Item Error: " + msg) {}
};
class PaymentException : public BaseException {
public:
    explicit PaymentException(const std::string& msg) : BaseException("Payment Error: " + msg) {}
};
class ReservationException : public BaseException {
public:
    explicit ReservationException(const std::string& msg) : BaseException("Reservation Error: " + msg) {}
};
class ReservationCancelException : public BaseException {
public:
    explicit ReservationCancelException(const std::string& msg) : BaseException("Reservation Cancel Error: " + msg) {}
};
class TableException : public BaseException {
public:
    explicit TableException(const std::string& msg) : BaseException("Table Error: " + msg) {}
};
class CustomerException : public BaseException {
public:
    explicit CustomerException(const std::string& msg) : BaseException("Customer Error: " + msg) {}
};
class EmployeeException : public BaseException {
public:
    explicit EmployeeException(const std::string& msg) : BaseException("Employee Error: " + msg) {}
};
class TipException : public BaseException {
public:
    explicit TipException(const std::string& msg) : BaseException("Tip Error: " + msg) {}
};
class BillSplitterException : public BaseException {
public:
    explicit BillSplitterException(const std::string& msg) : BaseException("Bill Splitter Error: " + msg) {}
};
class MenuException : public BaseException {
public:
    explicit MenuException(const std::string& msg) : BaseException("Menu Error: " + msg) {}
};
class RecipeException : public BaseException {
public:
    explicit RecipeException(const std::string& msg) : BaseException("Recipe Error: " + msg) {}
};

class KitchenScheduleException : public BaseException {
public:
    explicit KitchenScheduleException(const std::string& msg) : BaseException("Kitchen Schedule Error: " + msg) {}
};
