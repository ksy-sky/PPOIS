#pragma once
#include <vector>
#include <string>
#include "Reservation.h"

class ReservationService {
public:
    ReservationService();  
    Reservation* createReservation(Reservation* reservation);
    void cancelReservation(Reservation* reservation);
    const std::vector<Reservation*>& getActiveReservations() const;
    const std::vector<Reservation*>& getArchivedReservations() const;
    Reservation* getReservationById(int reservationId) const;
private:
    std::vector<Reservation*> activeReservations;
    std::vector<Reservation*> archivedReservations;
};
