#pragma once
#include <string>

namespace KalAcademyFlightReservation
{
	class Passenger
	{
	public:
		Passenger() = default;
		Passenger(const std::string& lastName, const std::string& firstName, const std::string& dateofBirth, const std::string& gender, const std::string& address, const unsigned int phone, const unsigned int ccNumber);
		~Passenger();

		void setId(const int id);
		const int getId() const;

		void setLastName(const std::string& lastName);
		const std::string& getLastName() const;

		void setFirstName(const std::string& firstName);
		const std::string& getFirstName() const;

		void setDateofBirth(const std::string& dateofBirth);
		const std::string& getDateofBirth() const;

		void setGender(const std::string& gender);
		const std::string& getGender() const;

		void setAddress(const std::string& address);
		const std::string& getAddress() const;

		void setPhone(const unsigned int phone);
		const unsigned int getPhone() const;

		void setCCNumber(const unsigned int ccNumber);
		const unsigned int getCCNumber() const;

	private:
		unsigned int id;
		std::string lastName;
		std::string firstName;
		std::string dateOfBirth;
		std::string gender;
		std::string address;
		unsigned int phone;
		unsigned int ccNumber;
	};
}