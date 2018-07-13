#pragma once

#include "Flight.h"
#include "Passenger.h"
#include "Ticket.h"
#include <vector>

namespace KalAcademyFlightReservation
{
	class DataAccess
	{
	public:

		DataAccess();

		// Returns list of one-way Flight objects that match the specified search criteria {origin, destination and date}.
		std::vector<Flight> GetFlightSchedule(std::string origin, std::string destination, tm date)
		{
			return vector<Flight>();
		}

		// Returns Flight for the specified flight number.
		// Returns nullptr if invalid flight number is specified.
		Flight* GetFlightInformation(int flightNumber)
		{
			return nullptr;
		}

		// Returns Passenger for the specified PassportId which is unique identifier for a passenger.
		// Returns nullptr if passenger corresponding to specified passportId is not found.
		Passenger* GetPassengerInformation(string passportId);

		// Returns Ticket for the specified ticket number.
		// Returns nullptr if ticket corresponding to the specified ticket number is not found.
		Ticket* GetTicketInformation(int ticketNo)
		{
			return nullptr;
		}

		void SaveFlights();

		std::vector<Flight*>& getFlights();

	private:

		const string filename = "flights.txt";

		vector<Flight*> mFlights;

		vector<string> split(const string& str, const char& delim);

		bool fileExists();

		vector<Flight*> ReadFlights();
	};
}
