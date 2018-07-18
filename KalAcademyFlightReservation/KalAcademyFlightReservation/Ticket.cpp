#include "stdafx.h"
#include "Ticket.h"
#include <string>
#include "Flight.h"
#include "Passenger.h"

namespace KalAcademyFlightReservation
{
	int Ticket::lastTicketNumber = 0;

	Ticket::Ticket(Seat* seat, Passenger* passenger, string ticketNumber)
	{
		mSeat = seat;
		mPassenger = passenger;
		mTicketNumber = ticketNumber;
	}

	const Seat* Ticket::getSeat() const
	{
		return mSeat;
	}

	Passenger* Ticket::getPassenger() const
	{
		return mPassenger;
	}

	const string Ticket::getTicketNumber() const
	{
		return mTicketNumber;
	}
}
