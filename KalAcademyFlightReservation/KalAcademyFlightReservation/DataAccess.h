#pragma once

#include "Flight.h"
#include <vector>

namespace KalAcademyFlightReservation
{
	class DataAccess
	{
	public:

		void AddFlights(list<Flight>& fligths)
		{
			ofstream flightFile;
			flightFile.open("flights.txt");

			for (list<Flight>::const_iterator iterator = fligths.begin(); iterator != fligths.end(); ++iterator)
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

		list<Flight> ReadFlights()
		{
			list<Flight> flights;
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
