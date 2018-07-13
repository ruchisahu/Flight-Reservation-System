#include "stdafx.h"
#include "FlightReservation.h"

namespace KalAcademyFlightReservation
{
	FlightReservation::FlightReservation(Flight * flight)
	{
		mFlight = flight;
	}

	bool FlightReservation::IsSeatAvailable(const int row, const int aisle, SeatCategory seatCategory)
	{
		// check if the seat is not already reserved
		for (vector<Seat>::const_iterator reservedSeat = mReservedSeats.begin(); reservedSeat != mReservedSeats.end(); ++reservedSeat)
		{
			if ((*reservedSeat).getRow() == row && (*reservedSeat).getAisle() == aisle)
			{
				return false;
			}
		}

		// check that the seat is within plane boundaries
		vector<SeatDefinition> seatDefinitions = mFlight->getSeatDefinitions();
		for (vector<SeatDefinition>::const_iterator seatDefinition = seatDefinitions.begin(); seatDefinition != seatDefinitions.end(); ++seatDefinition)
		{
			if (row >= (*seatDefinition).getRowStart() && row <= (*seatDefinition).getRowEnd() && aisle <= (*seatDefinition).getSeatsPerAisle() && (*seatDefinition).getSeatCategory() == seatCategory)
			{
				return true;
			}
		}

		return false;
	}
}
