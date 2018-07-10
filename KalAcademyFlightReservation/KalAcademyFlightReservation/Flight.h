#pragma once
#include <string>

namespace KalAcademyFlightReservation
{
	class Flight
	{
	public:
		//seating capacity of plane
		const static unsigned int seatingCapacity = 100;

		Flight() = default;
		Flight(const unsigned int id, const std::string& airline, const std::string& arrivalTime);
		~Flight();

		void setId(const int id);
		const int getId() const;

		void setAirline(const std::string& airline);
		const std::string& getAirline() const;

		void setSeat(const unsigned int capacity);
		const bool* getSeats() const;

		void setArrivalTime(const std::string& arrivalTime);
		const std::string& getArrivalTime() const;

	private:
		unsigned int id;
		std::string airline;
		bool seats[seatingCapacity];
		std::string arrivalTime;
	};
}

