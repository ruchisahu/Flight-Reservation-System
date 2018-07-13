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

	void Flight::setSeatDefinitions(const std::vector<SeatDefinition*>& seats)
	{
		mSeats = seats;
	}
	std::vector<SeatDefinition*>& Flight::getSeatDefinitions()
	{
		return mSeats;
	}

	bool Flight::IsSeatAvailable(const int row, const int aisle, SeatCategory seatCategory)
	{
		// check if the seat is not already reserved
		for (vector<Ticket*>::const_iterator ticket = mTickets.begin(); ticket != mTickets.end(); ++ticket)
		{
			const Seat* seat = (*ticket)->getSeat();
			if (seat->getRow() == row && seat->getAisle() == aisle)
			{
				return false;
			}
		}

		// check that the seat is within plane boundaries
		SeatDefinition* seatDefinition = getSeatDefinition(row, aisle, seatCategory);

		return seatDefinition != NULL;
	}

	void Flight::ReserveSeat(const int row, const int aisle, SeatCategory seatCategory, Passenger* passenger)
	{
		SeatDefinition* seatDefinition = getSeatDefinition(row, aisle, seatCategory);
		if (seatDefinition != NULL)
		{
			Seat* seat = new Seat(row, aisle, seatDefinition->getCost(), seatCategory);
			Ticket* ticket = new Ticket(seat, passenger);
			mTickets.push_back(ticket);
		}
	}

	std::vector<Ticket*>& Flight::getTickets()
	{
		return mTickets;
	}

	SeatDefinition* Flight::getSeatDefinition(const int row, const int aisle, SeatCategory seatCategory) const
	{
		for (vector<SeatDefinition*>::const_iterator seatDefinition = mSeats.begin(); seatDefinition != mSeats.end(); ++seatDefinition)
		{
			if (row >= (*seatDefinition)->getRowStart() && row <= (*seatDefinition)->getRowEnd() && aisle <= (*seatDefinition)->getSeatsPerAisle() && (*seatDefinition)->getSeatCategory() == seatCategory)
			{
				return *seatDefinition;
			}
		}

		return NULL;
	}
}
