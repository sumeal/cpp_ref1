#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdlib>
#include <sstream>

PhoneBook::PhoneBook(){
	total = 0;
	index = 0;
};

void PhoneBook::addContact() {
	contacts[index].addValue();
	index = (index + 1) % 8;
	if (total < 8)
		total++;
};

void PhoneBook::displayAll() {
	int i = 0;
	std::cout << "---------------------------------------------\n";
	std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
	std::cout << "---------------------------------------------\n";
	while (i < total) {
		contacts[i].displayone(i);
		i++;
	}
	std::cout << "---------------------------------------------\n";

}

void PhoneBook::searchContact() {
	std::string input;
	int userIndex;
	if (total == 0) {
		std::cout << "Phonebook is empty, add more contact to search.\n";
		return;
	}
	displayAll();
	std::cout << "Please enter the index than you want (0 to return) : \n";
	while (1) {
		if (!std::getline(std::cin, input)) {
			std::cout << "Exiting now...\n";
			exit(0);
		}
		std::stringstream ss(input);
		ss >> userIndex;
		if (ss.fail())
		{
			std::cout << "Please input value between 1 - 8\n";
			continue;
		}
		if (userIndex == 0) return ;
		else if (userIndex > 8 || userIndex < 0) {
			std::cout << "Please input value between 1 - 8\n";
		}
		else if (userIndex > total) {
			std::cout << "Your contact does not exist, please input another number\n";
		}
		else {
			contacts[userIndex - 1].displaytwo();
			return ;
		}
	}
}