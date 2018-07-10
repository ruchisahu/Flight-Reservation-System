#pragma once
#include <string>
#include "Passenger.h";
#include"Ticket.h";
#include "Flight.h";
#include <ctime>
#include <vector>

class Controller
{
public:
    //Getters
    
    Flight GetFlightInformation(int flightNumber);

    std::vector<Flight> GetFlightSchedule(std::string origin,std::string destination,tm date);

    Passenger GetPassengerInformation(int passPortId);

    Ticket GetTicketInformation(int ticketNo);
};