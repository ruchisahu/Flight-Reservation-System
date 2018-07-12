#pragma once
#include <string>

namespace KalAcademyFlightReservation {

	enum SeatCategory
	{
		Economy = 1, Business = 2
	};
	class Seat
	{
	public:
		Seat() = default;
		Seat(const int rowStart, const int rowEnd, int cost, enum seatCategory);
			
		void setRowStart(const int rowStart);
		const int getRowStart() const;

		void setRowEnd(const int rowEnd);
		const int getRowEnd() const;

		void setCost(int cost);
		int getCost() const;

	private:
		int mRowStart;
		int mRowEnd;
		int mCost;
		

	};
}
