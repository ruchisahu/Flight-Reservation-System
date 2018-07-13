#pragma once
#include <string>
#include "SeatCategory.h"

namespace KalAcademyFlightReservation {

	class Seat
	{
	public:
		Seat() = default;
		Seat(const int row, const int aisle, int cost, SeatCategory seatClass);
			
		const int getRow() const;

		const int getAisle() const;

		int getCost() const;

		SeatCategory getClass() const;

	private:
		int mRow;
		int mAisle;
		int mCost;
		SeatCategory mSeatClass;
	};
}
