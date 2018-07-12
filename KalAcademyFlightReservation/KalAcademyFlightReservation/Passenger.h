#pragma once
#include <string>

namespace KalAcademyFlightReservation {
	class Passenger
	{
	public:
		Passenger() = default;
		Passenger(const std::string& firstName, const std::string& lastName, const std::string& dateOfBirth,
			const std::string& gender, const std::string& address, const std::string& phone, const std::string& email);
		//AddPassanger();
		//DisplayPassangerInfo() const;
		void setFirstName(const std::string& firstName);
		const std::string& getFirstName() const;

		void setLastName(const std::string& lastName);
		const std::string& getLastName() const;

		void setDateOfBirth(const std::string& dateOfBirth);
		const std::string& getDateOfBirth() const;

		void setGender(const std::string& gender);
		const std::string& getGender() const;

		void setAddress(const std::string& address);
		const std::string& getAddress() const;

		void setPhone(const std::string& phone);
		const std::string& getPhone() const;

		void setEmail(const std::string& email);
		const std::string& getEmail() const;

	private:
		std::string mFirstName;
		std::string mLastName;
		std::string mDateOfBirth;
		std::string mGender;
		std::string mAddress;
		std::string mPhone;
		std::string mEmail;

	};
}
