#include "stdafx.h"
#include "Location.h"
#include "Flight.h"
#include <string>
#include <array>

namespace KalAcademyFlightReservation
{
	Location::Location(const unsigned int id, const std::string& location)
	{
		this->id = id;
		this->location = location;
	}
	Location::~Location()
	{
	}

	void Location::setId(const int id)
	{
		this->id = id;
	}

	const int Location::getId() const
	{
		return id;
	}

	void Location::setLocation(const std::string& location)
	{
		this->location = location;
	}

	const std::string& Location::getLocation() const
	{
		return location;
	}

	//void Location::addArrivals(const Flight flights[])
	//{
	//	// will be changing so not set?
	//}

	//const Flight*& Location::getArrivals() const
	//{
	//	return arrivals;
	//}
}