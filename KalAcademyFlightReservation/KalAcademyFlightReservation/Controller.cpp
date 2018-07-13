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
   /* std::vector<Flight> Controller::GetFlightSchedule(std::string origin, std::string destination, tm date)
    {
    }*/

    // Returns Flight for the specified flight number.
    // Returns nullptr if invalid flight number is specified.
   /* Flight* Controller::GetFlightInformation(int flightNumber)
    {
    }
*/
    // Returns Passenger for the specified PassportId which is unique identifier for a passenger.
    // Returns nullptr if passenger corresponding to specified passportId is not found.
   /* Passenger* Controller::GetPassengerInformation(int passportId)
    {
    }*/

    // Returns Ticket for the specified ticket number.
    // Returns nullptr if ticket corresponding to the specified ticket number is not found.
    /*Ticket* Controller::GetTicketInformation(int ticketNo)
    {
    }*/
}