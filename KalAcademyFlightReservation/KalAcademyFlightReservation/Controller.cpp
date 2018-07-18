#include "stdafx.h"
#include <string>
#include <vector>
#include "Passenger.h"
#include"Ticket.h"
#include "Flight.h"
#include "DataAccess.h"
#include "Controller.h"

namespace KalAcademyFlightReservation
{
    // Default constructor - creates an instance of DataAccess class.
    Controller::Controller()
    {
        dataAccess = new DataAccess();
    }

    // Destructor
    Controller::~Controller()
    {
        // Free the memory that was allocated in the constructor
        delete dataAccess;
    }

	// Returns list of one-way Flight objects that match the specified search criteria {origin, destination and date}.
	std::vector<Flight*> Controller::GetFlightSchedule(string origin, string destination, string date)
	{
		return dataAccess->GetFlightSchedule(origin, destination, date);
	}

	// Returns Flight for the specified flight number.
	// Returns nullptr if invalid flight number is specified.
	Flight* Controller::GetFlightInformation(int flightNumber)
	{
		return dataAccess->GetFlightInformation(flightNumber);
	}

	// Returns Passenger for the specified PassportId which is unique identifier for a passenger.
	// Returns nullptr if passenger corresponding to specified passportId is not found.
	Passenger* Controller::GetPassengerInformation(string passportId)
	{
		return dataAccess->GetPassengerInformation(passportId);
	}

	// Returns Ticket for the specified ticket number.
	// Returns nullptr if ticket corresponding to the specified ticket number is not found.
	Ticket* Controller::GetTicketInformation(string ticketNo) const
	{
		return dataAccess->GetTicketInformation(ticketNo);
	}
}