#pragma once
#include "stdafx.h"
#include "Seat.h"

namespace KalAcademyFlightReservation
{
	Seat::Seat(const int row, const int aisle, int cost, SeatCategory seatCategory)
	{
		mRow = row;
		mAisle = aisle;
		mCost = cost;
		mSeatCategory = seatCategory;
	}

	const int Seat::getRow() const
	{
		return mRow;
	}

	const int Seat::getAisle() const
	{
		return mAisle;
	}
}
