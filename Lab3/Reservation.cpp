#include "Reservation.h"
#include "Customer.h"
#include "Table.h"
#include "Admin.h"

Reservation::Reservation(int uniqueReservationId, Table* tableReference, const std::string& time, Admin* adminReference)
    : reservationId(uniqueReservationId), reservedTable(tableReference), reservationTime(time), createdByAdmin(adminReference), reservationStatus("Active") {}

bool Reservation::conflictsWith(const Reservation& otherReservation) const {
    return reservationTime == otherReservation.reservationTime &&
           reservedTable == otherReservation.reservedTable;
}
void Reservation::cancelReservation() { reservationStatus = "Cancelled"; }
bool Reservation::isUpcoming(const std::string& currentTime) const {
    return reservationStatus == "Active" && reservationTime > currentTime;
}
int Reservation::getId() const { return reservationId;}
Table* Reservation::getReservedTable() const { return reservedTable; }