#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact {
	private :
		std::string FirstName;
		std::string LastName;
		std::string Nickname;
		std::string PhoneNumber;
		std::string DarkestSecret;
	public :
		void addValue();
		void displayone(int i);
		void displaytwo();
		std::string truncateValue(std::string name);
		std::string toString(int i);
};

#endif