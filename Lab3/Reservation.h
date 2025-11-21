#pragma once
#include <string>
#include "Table.h"
#include "Admin.h"

class Reservation {
public:
    Reservation(int uniqueReservationId, Table* tableReference, const std::string& time, Admin* adminReference);
    int getId() const;
    Table* getReservedTable() const;
    bool conflictsWith(const Reservation& otherReservation) const;
    void cancelReservation();
    bool isUpcoming(const std::string& currentTime) const;
private:
    int reservationId;
    Table* reservedTable;
    std::string reservationTime;
    Admin* createdByAdmin;
    std::string reservationStatus;
};
