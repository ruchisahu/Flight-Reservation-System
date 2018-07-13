#pragma once
#include "stdafx.h"
#include "SeatDefinition.h"

namespace KalAcademyFlightReservation
{
	SeatDefinition::SeatDefinition(const int rowStart, const int rowEnd, const int seatsPerAisle, int cost, SeatCategory seatCategory)
	{
		mRowStart = rowStart;
		mRowEnd = rowEnd;
		mSeatsPerAisle = seatsPerAisle;
		mCost = cost;
		mSeatCategory = seatCategory;
	}

	const int SeatDefinition::getRowStart() const
	{
		return mRowStart;
	}

	const int SeatDefinition::getRowEnd() const
	{
		return mRowEnd;
	}

	int SeatDefinition::getCost() const
	{
		return mCost;
	}

	const int SeatDefinition::getSeatsPerAisle() const
	{
		return mSeatsPerAisle;
	}

	const SeatCategory SeatDefinition::getSeatCategory() const
	{
		return mSeatCategory;
	}
}
