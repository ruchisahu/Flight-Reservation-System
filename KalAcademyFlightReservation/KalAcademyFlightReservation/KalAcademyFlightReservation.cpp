// KalAcademyFlightReservation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Flight.h"
#include "DataAccess.h"
#include "Controller.h"
#include<time.h>
#include <windows.h> 
#include <iostream>
#include <string>

using namespace std;


using namespace KalAcademyFlightReservation;

int selection = 0, flightNumber, TicketNo, b;
string origin;
string destination, passportId, flight, dateOfBirth, gender, address, phone, email, date;

int traveler = 0, ticket;
string class1 = "ec";
char op = '0';
bool flag;
void menu();
void Reserve();
void UserInfo();
void UserRegistration();
void flightSchedule();
void flightDetail();
void TicketInformation();
void Exit();
DataAccess dataAccess;
Controller controller;
vector<Flight*>& flights = dataAccess.getFlights();
//Set position on screen
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
//Retrun Local date/time
void date_times()
{
	int aday, amonth, ayear, ahour, amin, asec;
	SYSTEMTIME t;		//pre defined in time.h header

	GetLocalTime(&t);

	aday = t.wDay, amonth = t.wMonth, ayear = t.wYear, ahour = t.wHour, amin = t.wMinute, asec = t.wSecond;
	cout << aday << ":" << amonth << ":" << ayear << ":" << ahour << ":" << amin << ":" << asec << endl;
}

//test dataset

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
		Passenger* passenger = new Passenger("firstName1", "lastName1", "dateOfBirth1", "gender1", "address1", "phone1", "email1", "111");
		flight->ReserveSeat(1, 1, SeatCategory::Business, passenger);
	}
	isSeatAvailable = flight->IsSeatAvailable(1, 1, SeatCategory::Business);

	isSeatAvailable = flight->IsSeatAvailable(1, 1, SeatCategory::Economy);
	isSeatAvailable = flight->IsSeatAvailable(11, 2, SeatCategory::Economy);
	if (isSeatAvailable)
	{
		Passenger* passenger = new Passenger("firstName2", "lastName2", "dateOfBirth2", "gender2", "address2", "phone2", "email2", "222");
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
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int k = 3;               //color number
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = 25;
	cfi.FontFamily = FF_SWISS;
	cfi.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	cout << "Local time:";

	date_times();
	system("color 8E");
	//SetConsoleTextAttribute(hConsole, k);
	gotoxy(35, 5);
	cout << " Welcome to Flight Reservation System:" << endl;
	//system("color cc");
	gotoxy(35, 6);
	cout << "........................................" << endl;
	cout << endl;
	menu();

}
//display menu for flight  Reservation System
void menu()
{
	//system("cls");
	flag = true;
	cout << endl;
	selection = 0;
	cout << " Please choose from the following options - \n";
	cout << "\n\n";
	cout << " 1. Reserve a seat.\n";
	cout << " 2. Flight Schedule.\n";
	cout << " 3. Display Passenger Information.\n";
	cout << " 4. Flight Detail.\n";
	cout << " 5. User Ticket Info.\n";
	cout << " 6. Exit.\n";
	cout << "\t";
	cin >> selection;                                 //select option
	while (flag != false)
	{

		switch (selection)
		{
		case 1:

			Reserve();
		case 2:

			flightSchedule();

		case 3:

			UserInfo();
		case 4:

			flightDetail();
		case 5:

			TicketInformation();
		case 6:
			Exit();
		default:
			cerr << "Unknown Command" << endl;
			break;
		}
	}
}
//Reserve flight
void Reserve()
{
	system("cls");
	gotoxy(40, 5);
	cout << "Book a Flight " << endl;
	cout << "NOTE: Available Options(NY,Dallas):" << endl;
	gotoxy(5, 10);
	cout << "Enter valid destination:";
	cin >> origin;
	while ((origin != "NY") && (origin != "Dallas"))
	{

		cout << "invalid origin Enter again:" << endl;
		cin >> origin;
	}

	cout << " Please enter destination - " << endl;
	cin >> destination;
	while ((destination != "NY") && (destination != "Dallas"))
	{
		cout << "invalid destination Enter again:" << endl;
		cin >> destination;
	}
	cout << " Please enter departure date - " << endl;
	cin >> date;
	//	cout << " Please enter number of travelers: "<<endl;
	//	cin >> traveler;
	cout << " Please enter class: Choose between  Business and Economy " << endl;
	cin >> class1;

	while ((class1 != "Business") && (class1 != "Economy"))
	{

		cout << "invalid class Enter again:" << endl;
		cin >> class1;
	}
	//cout << "list of avalaible flights " << endl;
	//cout <<"controller.GetFlightSchedule(origin, destination, date)" <<endl;
	//cout << "which flight you want to book" <<endl;
	//cin<<
	cout << " Do want to continue:" << endl;
	cout << " y to continue :" << endl;
	cout << "back to main menu:";
	cin >> op;
	if (op == 'y')
	{
		system("cls");
		UserRegistration();
	}
	else if (op == 'n')
	{
		menu();
	}
	else
		Exit();
}

//User Registration required by reseve function.
void UserRegistration()
{
	string Fname, Lname;
	string passportId;
	int phoneno;
	Flight* flight = new Flight("DL111", "Delta Airline", "7/13/2018 8:00:00", "7/13/2018 12:00:00", "NY", "Dallas");
	flights.push_back(flight);

	cout << " Please enter user First name - " << endl;
	cin >> Fname;
	cout << " Please enter user Last name - " << endl;
	cin >> Lname;
	cout << " Please enter date of Birth(mm/dd/yyyy) - " << endl;
	cin >> dateOfBirth;
	cout << " Please enter valid Address - " << endl;
	cin >> address;
	cout << " Gender- " << endl;
	cin >> gender;
	cout << " phone number- " << endl;
	cin >> phone;
	cout << " Email- " << endl;
	cin >> email;
	cout << " Please enter unique id/passport - " << endl;
	cin >> passportId;

	if (Fname == "0" | passportId == "0") //make sure a username/password has been set
	{
		cout << " Invalid name/passport " << endl;
		Sleep(4);
		menu();
	}
	else
	{
		cout << "  USERNAME AND PASSPORT SET." << endl;
		vector<SeatDefinition*> seatDefinitions;
		seatDefinitions.push_back(new SeatDefinition(1, 10, 5, 100, SeatCategory::Business));
		seatDefinitions.push_back(new SeatDefinition(11, 30, 5, 10, SeatCategory::Economy));
		flight->setSeatDefinitions(seatDefinitions);

		dataAccess.SaveFlights();

		Passenger* passenger = new Passenger(Fname, Lname, dateOfBirth, gender, address, phone, email, passportId);
		flight->ReserveSeat(1, 1, SeatCategory::Business, passenger);
		dataAccess.SaveFlights();
		Sleep(4);
		system("cls");
		menu();

	}

}
void flightSchedule()
{
	system("cls");
	gotoxy(50, 10);
	//dataAccess.ReadRecord("Delta Airline");
	cout << "Flight Schedule: " << endl;
	gotoxy(50, 20);
	cout << "list of all flights \n";
	cout << "controller.GetFlightSchedule(origin, destination, date)";
	system("cls");
	menu();
}
//User Information required bu menu selection "3".Based on passport Id this function will provide all other information.
void  UserInfo()
{
	system("cls");
	int b;
	cout << "Inter your passport Number" << endl;
	cin >> passportId;
	cout << "User Information: \n";
	Passenger *result = controller.GetPassengerInformation(passportId);
	cout << " first name:" << result->getFirstName() << endl;
	cout << " Last name:" << result->getLastName() << endl;
	cout << " date of Birth:" << result->getDateOfBirth() << endl;
	cout << " Email Address:" << result->getPhone() << endl;

	cout << "back to main menu Press 1 or to exit press any key:" << endl;
	cin >> b;
	if (b == 1)
	{
		system("cls");
		menu();
	}
	else
		Exit();

}
//flight detail based on menu selection "4".
void flightDetail()
{
	int b;
	system("cls");
	Flight *result = controller.GetFlightInformation(flightNumber);
	cout << "Inter your flight Number" << endl;
	cin >> flightNumber;
	cout << "Company Name:" << result->getCompany() << endl;
	cout << "Arrival DateTime:" << result->getArrivalDateTime() << endl;
	cout << "DepartureDateTime:" << result->getDepartureDateTime() << endl;
	cout << "Destination:" << result->getDestination() << endl;
	cout << "Origin" << result->getOrigin() << endl;
	//cout << "Seat Availability:"<<result->IsSeatAvailable() <<endl;

	cout << "back to main menu Press 1 or to exit press any key:" << endl;
	cin >> b;
	if (b == 1)
	{
		system("cls");
		menu();
	}
	else
		Exit();



}
//ticket information based on menu selection 5.
void TicketInformation()
{
	system("cls");

	cout << "Inter your ticket number" << endl;
	cin >> TicketNo;
	Ticket *result = controller.GetTicketInformation(TicketNo);
	cout << result->getPassenger();
	cout << result->getSeat();
	cout << "back to main menu Press 1 or to exit press any key:" << endl;
	cin >> b;
	if (b == 1)
	{
		system("cls");
		menu();
	}
	else
		Exit();

}
//exit from screen 
void Exit()
{
	Sleep(50);
	cout << " Thankyou for getting in touch !\n";
	Sleep(800);

	flag = false;

}






