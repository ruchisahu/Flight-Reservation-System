#include "stdafx.h"
#include "DataAccess.h"

namespace KalAcademyFlightReservation
{
	void DataAccess::WriteDataToFile(vector<Flight*> const& fligths, string filename)
	{
		ofstream flightFile;
		flightFile.open(filename);

		for (vector<Flight*>::const_iterator iterator = fligths.begin(); iterator != fligths.end(); ++iterator)
		{
			Flight* flight = *iterator;

			flightFile << "Flight;";
			flightFile << flight->getCompany() << ";";
			flightFile << flight->getDepartureDateTime() << ";";
			flightFile << flight->getArrivalDateTime() << ";";
			flightFile << flight->getOrigin() << ";";
			flightFile << flight->getDestination() << ";";
			flightFile << "\n";

			for (vector<SeatDefinition*>::iterator seatDefinitionIterator = flight->getSeatDefinitions().begin(); seatDefinitionIterator != flight->getSeatDefinitions().end(); ++seatDefinitionIterator)
			{
				const SeatDefinition* seatDefinition = *seatDefinitionIterator;

				flightFile << "SeatDefinition;";
				flightFile << seatDefinition->getRowStart() << ";";
				flightFile << seatDefinition->getRowEnd() << ";";
				flightFile << seatDefinition->getSeatsPerAisle() << ";";
				flightFile << seatDefinition->getCost() << ";";
				flightFile << seatDefinition->getSeatCategory() << ";";
				flightFile << "\n";
			}
		}

		flightFile.close();
	}

	vector<Flight*> DataAccess::ReadFlights(string filename)
	{
		vector<Flight*> flights;
		string line;
		ifstream flightFile(filename);
		if (flightFile.is_open())
		{
			Flight* flight = NULL;
			while (getline(flightFile, line))
			{
				vector<string> parts = split(line, ';');
				if (parts[0] == "Flight")
				{
					flight = new Flight(parts[1], parts[2], parts[3], parts[4], parts[5]);
					flights.push_back(flight);
				}
				else
				{
					if (parts[0] == "SeatDefinition")
					{
						int rowStart = stoi(parts[1]);
						int rowEnd = stoi(parts[2]);
						int seatsPerAisle = stoi(parts[3]);
						int cost = stoi(parts[4]);
						SeatCategory seatCategory = (SeatCategory)(stoi(parts[5]));
						SeatDefinition* seatDefinition = new SeatDefinition(rowStart, rowEnd, seatsPerAisle, cost, seatCategory);
						flight->getSeatDefinitions().push_back(seatDefinition);
					}
				}
			}
			flightFile.close();
		}

		return flights;
	}

	vector<string> DataAccess::split(const string& str, const char& delim)
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
}
