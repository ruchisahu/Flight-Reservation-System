#pragma once
#include "Flight.h"
#include "Passenger.h"

namespace KalAcademyFlightReservation
{
	class Ticket
	{
	public:
		Ticket() = default;
		Ticket(const unsigned int id, const Passenger& passenger, const Flight& flight);
		~Ticket();

		void setId(const int id);
		const int getId() const;

		void setPassenger(const Passenger& passenger);
		const Passenger& getPassenger() const;

		void setFlight(const Flight& flight);
		const Flight& getFlight() const;

	private:
		unsigned int id;
		Passenger passenger;
		Flight flight;
	};
}

