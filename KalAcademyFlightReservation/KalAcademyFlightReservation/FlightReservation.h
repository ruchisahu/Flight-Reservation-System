#pragma once
#include "Flight.h"

namespace KalAcademyFlightReservation {
	class FlightReservation
	{
	public:
		FlightReservation(Flight* flight);

		bool IsSeatAvailable(const int row, const int aisle, SeatCategory seatCategory);

	private:
		Flight* mFlight;
		vector<Seat> mReservedSeats;
	};
}
