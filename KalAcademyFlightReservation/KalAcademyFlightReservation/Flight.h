#pragma once
#include "SeatDefinition.h"
#include "Seat.h"
#include "Ticket.h"
#include <vector>

namespace KalAcademyFlightReservation {
	class Flight
	{
	public:
		Flight() = default;
		Flight(const std::string& company, const std::string& departureDateTime, const std::string& arrivalDateTime, const std::string& origin, const std::string& destination);
		
		void setCompany(const std::string& company);
		const std::string& getCompany() const;

		void setArrivalDateTime(const std::string& arrivalTime);
		const std::string& getArrivalDateTime() const ;

		void setDepartureDateTime(const std::string& departureTime);
		const std::string& getDepartureDateTime() const;

		void setOrigin(const std::string& origin);
		const std::string& getOrigin() const;
		
		void setDestination(const std::string& destination);
		const std::string& getDestination() const;

		void setSeatDefinitions(const std::vector<SeatDefinition*>& seats);
		std::vector<SeatDefinition*>& getSeatDefinitions();

		bool IsSeatAvailable(const int row, const int aisle, SeatCategory seatCategory);
		void ReserveSeat(const int row, const int aisle, SeatCategory seatCategory, Passenger* passenger);

		std::vector<Ticket*>& getTickets();

	private:
		std::string mCompany;
		std::string mArrivalDateTime;
		std::string mDepartureDateTime;
		std::string mOrigin;
		std::string mDestination;
		std::vector<SeatDefinition*> mSeats;
		vector<Ticket*> mTickets;

		SeatDefinition* getSeatDefinition(const int row, const int aisle, SeatCategory seatCategory) const;

		// ToDo:
		// destructor to delete each SeatDefinition because it belongs to a flight
	};
}
