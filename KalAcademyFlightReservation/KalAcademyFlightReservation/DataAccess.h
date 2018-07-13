#pragma once

#include "Flight.h"
#include <vector>

namespace KalAcademyFlightReservation
{
	class DataAccess
	{
	public:

		void WriteDataToFile(vector<Flight*> const& fligths, string filename);

		vector<Flight*> ReadFlights(string filename);

	private:

		vector<string> split(const string& str, const char& delim);
	};
}
