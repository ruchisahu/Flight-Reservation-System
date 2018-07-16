// KalAcademyFlightReservation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Flight.h"
#include "DataAccess.h"

using namespace KalAcademyFlightReservation;

void TestDataAccess()
{
	DataAccess dataAccess;
	vector<Flight*>& flights = dataAccess.getFlights();

	//flights.clear();

	Flight* flight = new Flight("123D", "Delta Airline", "7/13/2018 8:00:00", "7/13/2018 12:00:00", "NY", "Dallas");
	flights.push_back(flight);

	vector<SeatDefinition*> seatDefinitions;
	seatDefinitions.push_back(new SeatDefinition(1, 10, 5, 100, SeatCategory::Business));
	seatDefinitions.push_back(new SeatDefinition(11, 30, 5, 10, SeatCategory::Economy));
	flight->setSeatDefinitions(seatDefinitions);

	dataAccess.SaveFlights();

	bool isSeatAvailable = flight->IsSeatAvailable(1, 1, SeatCategory::Business);
	if (isSeatAvailable)
	{
		Passenger* passenger = new Passenger("firstName1", "lastName1", "dateOfBirth1", "gender1", "address1", "phone1", "email1", "passportId1");
		flight->ReserveSeat(1, 1, SeatCategory::Business, passenger);
	}
	isSeatAvailable = flight->IsSeatAvailable(1, 1, SeatCategory::Business);

	isSeatAvailable = flight->IsSeatAvailable(1, 1, SeatCategory::Economy);
	isSeatAvailable = flight->IsSeatAvailable(11, 2, SeatCategory::Economy);
	if (isSeatAvailable)
	{
		Passenger* passenger = new Passenger("firstName2", "lastName2", "dateOfBirth2", "gender2", "address2", "phone2", "email2", "passportId2");
		flight->ReserveSeat(11, 2, SeatCategory::Economy, passenger);
	}
	isSeatAvailable = flight->IsSeatAvailable(11, 2, SeatCategory::Economy);

	isSeatAvailable = flight->IsSeatAvailable(31, 1, SeatCategory::Economy);

	dataAccess.SaveFlights();

	Passenger* passenger = dataAccess.GetPassengerInformation("passportId1");
	passenger = dataAccess.GetPassengerInformation("passportId111");
}

int main()
{
	TestDataAccess();
	return 0;
}
