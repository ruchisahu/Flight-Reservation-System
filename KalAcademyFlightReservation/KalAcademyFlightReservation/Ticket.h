#pragma once
#include <string>
#include "Seat.h"
#include "Passenger.h"
#include "Flight.h"

namespace KalAcademyFlightReservation {
	class Ticket
	{
	public:
		Ticket() = default;
		Ticket(Seat* seat, const Passenger& passenger);

		const Seat* getSeat() const;

		void setPassenger(const Passenger& passenger);
		const Passenger& getPassenger() const;

	private:
		Seat* mSeat;
		Passenger mPassenger;
	};
}
