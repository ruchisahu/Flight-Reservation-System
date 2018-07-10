#include "stdafx.h"
#include "Ticket.h"
#include <string>
#include "Flight.h"
#include "Passenger.h"

namespace KalAcademyFlightReservation
{
	Ticket::Ticket(const unsigned int id, const Passenger& passenger, const Flight& flight)
	{
		this->id = id;
		this->passenger = passenger;
		this->flight = flight;
	}

	Ticket::~Ticket()
	{
	}

	void Ticket::setId(const int id)
	{
		this->id = id;
	}

	const int Ticket::getId() const
	{
		return id;
	}

	void Ticket::setPassenger(const Passenger& passenger)
	{
		this->passenger = passenger;
	}

	const Passenger & Ticket::getPassenger() const
	{
		return passenger;
	}

	void Ticket::setFlight(const Flight& flight)
	{
		this->flight = flight;
	}

	const Flight & Ticket::getFlight() const
	{
		return flight;
	}
}
