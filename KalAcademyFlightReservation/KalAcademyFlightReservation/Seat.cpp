#pragma once
#include "stdafx.h"
#include "Seat.h"

namespace KalAcademyFlightReservation
{
	Seat::Seat(const int rowStart, const int rowEnd, int cost, SeatCategory seatCategory)
	{
		mRowStart = rowStart;
		mRowEnd = rowEnd;
		mCost = cost;
		mSeatCategory = seatCategory;
	}
}
