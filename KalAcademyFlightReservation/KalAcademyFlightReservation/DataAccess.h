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
        Passenger* GetPassengerInformation(int passportId)
        {
            return nullptr;
        }

        // Returns Ticket for the specified ticket number.
        // Returns nullptr if ticket corresponding to the specified ticket number is not found.
        Ticket* GetTicketInformation(int ticketNo)
        {
            return nullptr;
        }

        void AddFlights(vector<Flight>& fligths)
		{
			ofstream flightFile;
			flightFile.open("flights.txt");

			for (vector<Flight>::const_iterator iterator = fligths.begin(); iterator != fligths.end(); ++iterator)
			{
				flightFile << (*iterator).getCompany();
				flightFile << ";";
				flightFile << (*iterator).getDepartureDateTime();
				flightFile << ";";
				flightFile << (*iterator).getArrivalDateTime();
				flightFile << ";";
				flightFile << (*iterator).getOrigin();
				flightFile << ";";
				flightFile << (*iterator).getDestination();
				flightFile << "\n";
			}

			flightFile.close();
		}

		vector<Flight> ReadFlights()
		{
			vector<Flight> flights;
			string line;
			ifstream flightFile("flights.txt");
			if (flightFile.is_open())
			{
				while (getline(flightFile, line))
				{
					vector<string> parts = split(line, ';');
					flights.push_back(Flight(parts[0], parts[1], parts[2], parts[3], parts[4]));
				}
				flightFile.close();
			}

			return flights;
		}

		vector<string> split(const string& str, const char& delim)
		{
			vector<string>result;

			size_t len = str.length();
			for (int j = 0, k = 0; j < len; j++)
			{
				if (str[j] == delim)
				{
					string ch = str.substr(k, j - k);
					k = j + 1;
					result.push_back(ch);
				}
				if (j == len - 1)
				{
					string ch = str.substr(k, j - k + 1);
					result.push_back(ch);
				}
			}
			return result;
		}

	};
}
