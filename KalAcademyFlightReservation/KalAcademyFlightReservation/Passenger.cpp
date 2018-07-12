#pragma once
#include "stdafx.h"

#include "Passenger.h"
#include <string>

using namespace std;

namespace KalAcademyFlightReservation
{
	Passenger::Passenger(const string& firstName, const string& lastName, const string& dateOfBirth, const string& gender, const string& address, const string& phone, const string& email)

		: mFirstName(firstName), mLastName(lastName), mDateOfBirth(dateOfBirth), mGender(gender), mAddress(address), mPhone(phone), mEmail(email)
	{
	}
	
	void Passenger::setFirstName(const string& firstName)
	{
		mFirstName = firstName;
	}

	const string& Passenger::getFirstName() const
	{
		return mFirstName;
	}

	void Passenger::setLastName(const string& lastName)
	{
		mLastName = lastName;
	}

	const string& Passenger::getLastName() const
	{
		return mLastName;
	}

	void Passenger::setDateOfBirth(const string& dateOfBirth)
	{
		mDateOfBirth = dateOfBirth;
	}
	const string& Passenger::getDateOfBirth() const
	{
		return mDateOfBirth;
	}

	void Passenger::setGender(const string& gender)
	{
		mGender = gender;
	}
	const string& Passenger::getGender() const
	{
		return mGender;
	}

	void Passenger::setAddress(const string& address)
	{
		mAddress = address;
	}
	const string& Passenger::getAddress() const
	{
		return mAddress;
	}

	void Passenger::setPhone(const string& phone)
	{
		mPhone = phone;
	}
	const string& Passenger::getPhone() const
	{
		return mPhone;
	}

	void Passenger::setEmail(const string& email)
	{
		mEmail = email;
	}
	const string& Passenger::getEmail() const
	{
		return mEmail;
	}


}
