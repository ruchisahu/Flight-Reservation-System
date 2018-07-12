#pragma once
#include "stdafx.h"
#include "Flight.h"
#include <string>
using namespace std;

namespace KalAcademyFlightReservation
{
	Flight::Flight(const string& company, const string& departureDateTime, const string& arrivalDateTime, const string& origin, const string& destination)
	{
		mCompany = company;
		mDepartureDateTime = departureDateTime;
		mArrivalDateTime = arrivalDateTime;
		mOrigin = origin;
		mDestination = destination;
	}

	void Flight::setCompany(const string& company)
	{
		mCompany = company;
	}
	const string& Flight::getCompany() const
	{
		return mCompany;
	}

	void Flight::setArrivalDateTime(const string& arrivalTime)
	{
		mArrivalDateTime = arrivalTime;
	}
	const string& Flight::getArrivalDateTime() const
	{
		return mArrivalDateTime;
	}

	void Flight::setDepartureDateTime(const string& departureTime)
	{
		mDepartureDateTime = departureTime;
	}
	const string& Flight::getDepartureDateTime() const
	{
		return mDepartureDateTime;
	}

	void Flight::setOrigin(const string& origin)
	{
		mOrigin = origin;
	}
	const string& Flight::getOrigin() const
	{
		return mOrigin;
	}

	void Flight::setDestination(const string& destination)
	{
		mDestination = destination;
	}
	const string& Flight::getDestination() const
	{
		return mDestination;
	}

	void Flight::setSeats(const std::list<Seat>& seats)
	{
		mSeats = seats;
	}
	const std::list<Seat>& Flight::getSeats() const
	{
		return mSeats;
	}
}
