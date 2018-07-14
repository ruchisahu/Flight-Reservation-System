#pragma once
#include <string>
#include "Passenger.h"
#include"Ticket.h"
#include "Flight.h"
#include <vector>
#include "DataAccess.h"

namespace KalAcademyFlightReservation
{
    class Controller
    {
    public:
        Controller();
        ~Controller();

        //Getters

        // Returns list of one-way Flight objects that match the specified search criteria {origin, destination and date}.
        std::vector<Flight> GetFlightSchedule(string origin, string destination, string date);

        // Returns Flight for the specified flight number.
        // Returns nullptr if invalid flight number is specified.
        Flight* GetFlightInformation(int flightNumber);

        // Returns Passenger for the specified PassportId which is unique identifier for a passenger.
        // Returns nullptr if passenger corresponding to specified passportId is not found.
        Passenger* GetPassengerInformation(string passportId);

        // Returns Ticket for the specified ticket number.
        // Returns nullptr if ticket corresponding to the specified ticket number is not found.
        Ticket* GetTicketInformation(int ticketNo);

    private:
        // DataAccess class member variable
        DataAccess *dataAccess;
    };
}