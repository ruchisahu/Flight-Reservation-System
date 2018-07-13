#include "stdafx.h"
#include "Ticket.h"
#include <string>
#include "Flight.h"
#include "Passenger.h"

namespace KalAcademyFlightReservation
{
	Ticket::Ticket(Seat* seat, Passenger* passenger)
	{
		mSeat = seat;
		mPassenger = passenger;
	}

	const Seat* Ticket::getSeat() const
	{
		return mSeat;
	}
}
