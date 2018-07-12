#pragma once
#include <string>
#include "Flight.h"

namespace KalAcademyFlightReservation
{
	class Location
	{
	public:
		Location() = default;
		Location(const unsigned int id, const std::string& location);
		~Location();

		void setId(const int id);
		const int getId() const;

		void setLocation(const std::string& location);
		const std::string& getLocation() const;

		//void addArrivals(const Flight flights[]);
		//const Flight*& getArrivals() const;

	private:
		unsigned int id;
		std::string location;
		//Flight arrivals[]; //will be changing?
	};
}

