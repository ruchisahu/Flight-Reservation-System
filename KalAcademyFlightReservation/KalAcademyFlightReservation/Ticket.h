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
		Ticket(const Seat& seat, const Passenger& passenger, const Flight& flight);

		void setSeat(const Seat& seat);
		const Seat& getSeat() const;

		void setPassenger(const Passenger& passenger);
		const Passenger& getPassenger() const;

		void setFlight(const Flight& flight);
		const Flight& getFlight() const;

	private:
		Seat mSeat;
		Passenger mPassenger;
		Flight mflight;
	};
}
