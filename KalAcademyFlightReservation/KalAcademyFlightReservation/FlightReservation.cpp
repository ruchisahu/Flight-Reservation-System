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
		for (vector<Ticket>::const_iterator ticket = mTickets.begin(); ticket != mTickets.end(); ++ticket)
		{
			const Seat* seat = (*ticket).getSeat();
			if (seat->getRow() == row && seat->getAisle() == aisle)
			{
				return false;
			}
		}

		// check that the seat is within plane boundaries
		SeatDefinition* seatDefinition = getSeatDefinition(row, aisle, seatCategory);

		return seatDefinition != NULL;
	}

	void FlightReservation::ReserveSeat(const int row, const int aisle, SeatCategory seatCategory, Passenger* passenger)
	{
		SeatDefinition* seatDefinition = getSeatDefinition(row, aisle, seatCategory);
		if (seatDefinition != NULL)
		{
			Seat* seat = new Seat(row, aisle, seatDefinition->getCost(), seatCategory);
			mTickets.push_back(Ticket(seat, passenger));
		}
	}

	SeatDefinition* FlightReservation::getSeatDefinition(const int row, const int aisle, SeatCategory seatCategory) const
	{
		vector<SeatDefinition*> seatDefinitions = mFlight->getSeatDefinitions();
		for (vector<SeatDefinition*>::const_iterator seatDefinition = seatDefinitions.begin(); seatDefinition != seatDefinitions.end(); ++seatDefinition)
		{
			if (row >= (*seatDefinition)->getRowStart() && row <= (*seatDefinition)->getRowEnd() && aisle <= (*seatDefinition)->getSeatsPerAisle() && (*seatDefinition)->getSeatCategory() == seatCategory)
			{
				return *seatDefinition;
			}
		}

		return NULL;
	}

}
