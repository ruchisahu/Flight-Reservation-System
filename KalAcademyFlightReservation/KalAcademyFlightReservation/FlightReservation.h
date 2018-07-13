#pragma once
#include "Flight.h"

namespace KalAcademyFlightReservation {
	class FlightReservation
	{
	public:
		FlightReservation(Flight* flight);

		bool IsSeatAvailable(const int row, const int aisle);

	private:
		Flight* mFlight;
		vector<Seat> mReservedSeats;
	};
}
