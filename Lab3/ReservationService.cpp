#include "ReservationService.h"
#include <algorithm>

ReservationService::ReservationService() 
    : activeReservations(), archivedReservations() {}
Reservation* ReservationService::createReservation(Reservation* reservation) {
    activeReservations.push_back(reservation);
    return reservation;
}
void ReservationService::cancelReservation(Reservation* reservation) {
    reservation->cancelReservation();
    activeReservations.erase(
        std::remove(activeReservations.begin(), activeReservations.end(), reservation),
        activeReservations.end()
    );
    archivedReservations.push_back(reservation);
}
const std::vector<Reservation*>& ReservationService::getActiveReservations() const { return activeReservations; }
const std::vector<Reservation*>& ReservationService::getArchivedReservations() const { return archivedReservations; }
Reservation* ReservationService::getReservationById(int reservationId) const {
    for (Reservation* res : activeReservations) {
        if (res->getId() == reservationId) return res;
    }
    for (Reservation* res : archivedReservations) {
        if (res->getId() == reservationId) return res;
    }
    return nullptr;
}
