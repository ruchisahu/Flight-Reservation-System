#include "stdafx.h"
#include "Passenger.h"
#include <string>

namespace KalAcademyFlightReservation
{
	Passenger::Passenger(const unsigned int id, const std::string& lastName, const std::string& firstName, const std::string& dateofBirth, const std::string& gender, const std::string& address, const unsigned int phone, const unsigned int ccNumber)
	{
		this->id = id;
		this->lastName = lastName;
		this->firstName = firstName;
		this->dateOfBirth = dateofBirth;
		this->gender = gender;
		this->address = address;
		this->phone = phone;
		this->ccNumber = ccNumber;
	}

	Passenger::~Passenger()
	{
	}

	void Passenger::setId(const int id)
	{
		this->id = id;
	}

	const int Passenger::getId() const
	{
		return id;
	}

	void Passenger::setLastName(const std::string& lastName)
	{
		this->lastName = lastName;
	}

	const std::string& Passenger::getLastName() const
	{
		return lastName;
	}

	void Passenger::setFirstName(const std::string& firstName)
	{
		this->firstName = firstName;
	}

	const std::string & Passenger::getFirstName() const
	{
		return firstName;
	}

	void Passenger::setDateofBirth(const std::string& dateofBirth)
	{
		this->dateOfBirth = dateOfBirth;
	}

	const std::string& Passenger::getDateofBirth() const
	{
		return dateOfBirth;
	}

	void Passenger::setGender(const std::string& gender)
	{
		this->gender = gender;
	}

	const std::string& Passenger::getGender() const
	{
		return gender;
	}

	void Passenger::setAddress(const std::string& address)
	{
		this->address = address;
	}

	const std::string& Passenger::getAddress() const
	{
		return address;
	}

	void Passenger::setPhone(const unsigned int phone)
	{
		this->phone = phone;
	}

	const unsigned int Passenger::getPhone() const
	{
		return phone;
	}

	void Passenger::setCCNumber(const unsigned int ccNumber)
	{
		this->ccNumber = ccNumber;
	}

	const unsigned int Passenger::getCCNumber() const
	{
		return ccNumber;
	}
}