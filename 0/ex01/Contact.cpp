#include "Contact.hpp"
#include <cstdlib>
#include <cstdlib>
#include <sstream>

void Contact::addValue() {
	while (1) {
		std::cout << "Enter first name\n";
		if(!std::getline(std::cin, FirstName)) {
			std::cout << "Exiting now...\n";
			exit(0);
		}
		if(FirstName.empty()) {
			std::cout << "Empty information not allowed !\n";
			continue ;
		}
		break ;
	}
	while (1) {
		std::cout << "Enter Last name\n";
		if(!std::getline(std::cin, LastName)) {
			std::cout << "Exiting now...\n";
			exit(0);
		}
		if(LastName.empty()) {
			std::cout << "Empty information not allowed !\n";
			continue ;
		}
		break ;
	}
	while (1) {
		std::cout << "Enter Nickname\n";
		if(!std::getline(std::cin, Nickname)) {
			std::cout << "Exiting now...\n";
			exit(0);
		}
		if(Nickname.empty()) {
			std::cout << "Empty information not allowed !\n";
			continue ;
		}
		break ;
	}
	while (1) {
		std::cout << "Enter Phone Number\n";
		if(!std::getline(std::cin, PhoneNumber)) {
			std::cout << "Exiting now...\n";
			exit(0);
		}
		if(PhoneNumber.empty()) {
			std::cout << "Empty information not allowed !\n";
			continue ;
		}
		break ;
	}
	while (1) {
		std::cout << "Enter Darkest Secret\n";
		if(!std::getline(std::cin, DarkestSecret)) {
			std::cout << "Exiting now...\n";
			exit(0);
		}
		if(DarkestSecret.empty()) {
			std::cout << "Empty information not allowed !\n";
			continue ;
		}
		break ;
	}
	std::cout << std::endl << "ADDED to phonebook !\n" << std::endl;
}

std::string Contact:: truncateValue(std::string name) {
	if (name.length() > 10)
		return name.substr(0,9) + ".";
	else
		return name;
}

std::string Contact::toString(int i) {
	std::stringstream ss;
	ss << i;
	return ss.str();
}

void Contact::displayone(int i) {
	std::cout << "|" << std::setw(10) << truncateValue(toString(i + 1))
		  	  << "|" << std::setw(10) << truncateValue(FirstName)
		  	  << "|" << std::setw(10) << truncateValue(LastName)
			  << "|" << std::setw(10) << truncateValue(Nickname)
			  << "|" << std::endl;
}

void Contact::displaytwo() {
	std::cout << "First Name : " << FirstName << std::endl
			  << "Last Name : " << LastName << std::endl
			  << "Nickname : " << Nickname << std::endl
			  << "Phone Number : " << PhoneNumber << std::endl
			  << "Darkest Secret : " << DarkestSecret << std::endl;

}
