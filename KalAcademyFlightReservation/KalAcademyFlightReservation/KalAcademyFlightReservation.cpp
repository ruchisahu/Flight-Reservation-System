// KalAcademyFlightReservation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Flight.h"
#include "DataAccess.h"

using namespace KalAcademyFlightReservation;

int main()
{
	vector<Flight> flights;
	/*flights.push_back(Flight("American Airlines", "7/10/2018 23:00:00", "7/11/2018 3:00:00", "SEA", "NY"));
	flights.push_back(Flight("Continental Airlines", "7/11/2018 23:00:00", "7/12/2018 3:00:00", "NY", "SEA"));*/
	flights.push_back(Flight("Delta Airline", "7/13/2018 8:00:00", "7/13/2018 12:00:00", "NY", "Dallas"));

	DataAccess dataAccess;
	dataAccess.AddFlights(flights);
	dataAccess.split("Delta Airline;7/13/2018 8:00:00;7/13/2018 12:00:00;NY;Dallas", ';');

    return 0;
}
