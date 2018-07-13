#pragma once
#include "Flight.h"
#include "Ticket.h"

namespace KalAcademyFlightReservation {
	class FlightReservation
	{
	public:
		FlightReservation(Flight* flight);

		bool IsSeatAvailable(const int row, const int aisle, SeatCategory seatCategory);
		void ReserveSeat(const int row, const int aisle, SeatCategory seatCategory, Passenger* passenger);

	private:

		SeatDefinition* getSeatDefinition(const int row, const int aisle, SeatCategory seatCategory) const;

		Flight* mFlight;
		vector<Ticket> mTickets;
	};
}
