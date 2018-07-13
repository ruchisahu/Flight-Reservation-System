#pragma once
#include <string>
#include "SeatCategory.h"

namespace KalAcademyFlightReservation {

	class Seat
	{
	public:
		Seat() = default;
		Seat(const int row, const int aisle, int cost, SeatCategory seatCategory);
			
		const int getRow() const;

		const int getAisle() const;

		void setCost(int cost);
		int getCost() const;

	private:
		int mRow;
		int mAisle;
		int mCost;
		SeatCategory mSeatCategory;
	};
}
