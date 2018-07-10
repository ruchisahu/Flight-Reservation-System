#include "stdafx.h"
#include "Flight.h"
#include <string>

namespace KalAcademyFlightReservation
{
	Flight::Flight(const unsigned int id, const std::string& airline, const std::string& arrivalTime)
	{
		this->id = id;
		this->airline = airline;
		this->arrivalTime = arrivalTime;
	}


	Flight::~Flight()
	{
	}

	void Flight::setId(const int id)
	{
		this->id = id;
	}

	const int Flight::getId() const
	{
		return id;
	}

	void Flight::setAirline(const std::string & airline)
	{
		this->airline = airline;
	}

	const std::string & Flight::getAirline() const
	{
		return airline;
	}

	void Flight::setSeat(const unsigned int seatNumber)
	{
		seats[seatNumber - 1] = true;
	}

	const bool* Flight::getSeats() const
	{
		return seats;
	}

	void Flight::setArrivalTime(const std::string & arrivalTime)
	{
		this->arrivalTime = arrivalTime;
	}

	const std::string & Flight::getArrivalTime() const
	{
		return arrivalTime;
	}

}
