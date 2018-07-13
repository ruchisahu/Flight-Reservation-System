// KalAcademyFlightReservation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Flight.h"
#include "DataAccess.h"
#include "FlightReservation.h"

using namespace KalAcademyFlightReservation;

int main()
{
	vector<Flight*> flights;
	/*flights.push_back(Flight("American Airlines", "7/10/2018 23:00:00", "7/11/2018 3:00:00", "SEA", "NY"));
	flights.push_back(Flight("Continental Airlines", "7/11/2018 23:00:00", "7/12/2018 3:00:00", "NY", "SEA"));*/

	Flight* f1 = new Flight("Delta Airline", "7/13/2018 8:00:00", "7/13/2018 12:00:00", "NY", "Dallas");
	flights.push_back(f1);

	vector<SeatDefinition*> seatDefinitions;
	seatDefinitions.push_back(new SeatDefinition(1, 10, 5, 100, SeatCategory::Business));
	seatDefinitions.push_back(new SeatDefinition(11, 30, 5, 10, SeatCategory::Economy));
	f1->setSeatDefinitions(seatDefinitions);

	DataAccess dataAccess;
	dataAccess.WriteDataToFile(flights, "flights.txt");

	vector<Flight*> savedFlights = dataAccess.ReadFlights("flights.txt");

	FlightReservation flightReservation(f1);

	bool isSeatAvailable = flightReservation.IsSeatAvailable(1, 1, SeatCategory::Business);
	if (isSeatAvailable)
	{
		Passenger* passenger = nullptr;
		flightReservation.ReserveSeat(1, 1, SeatCategory::Business, passenger);
	}
	isSeatAvailable = flightReservation.IsSeatAvailable(1, 1, SeatCategory::Business);

	isSeatAvailable = flightReservation.IsSeatAvailable(1, 1, SeatCategory::Economy);
	isSeatAvailable = flightReservation.IsSeatAvailable(11, 2, SeatCategory::Economy);
	if (isSeatAvailable)
	{
		Passenger* passenger = nullptr;
		flightReservation.ReserveSeat(11, 2, SeatCategory::Economy, passenger);
	}
	isSeatAvailable = flightReservation.IsSeatAvailable(11, 2, SeatCategory::Economy);

	isSeatAvailable = flightReservation.IsSeatAvailable(31, 1, SeatCategory::Economy);

	//DataAccess dataAccess;
	//dataAccess.AddFlights(flights);
	//dataAccess.split("Delta Airline;7/13/2018 8:00:00;7/13/2018 12:00:00;NY;Dallas", ';');

	delete f1;

	return 0;
}
