#pragma once
#include <string>
#include "Seat.h"
#include "Passenger.h"

namespace KalAcademyFlightReservation {
	class Ticket
	{
	public:
		Ticket() = default;
		Ticket(Seat* seat, Passenger* passenger);

		const Seat* getSeat() const;

		const Passenger* getPassenger() const;

	private:
		Seat* mSeat;
		Passenger* mPassenger;

		// ToDo:
		// destructor to delete the Seat because the seat belongs only to a ticket
		// change mPassenger to be a pointer. Who's going to delete it ?
	};
}
