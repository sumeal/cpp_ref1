#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdlib>

int main()
{
	PhoneBook book;
	std::string cmd;

	while (1)
	{
		std::cout << "What can I help you with ? (ADD, SEARCH, EXIT)\n> ";
		if (!std::getline(std::cin, cmd)) {
			std::cout << "Exiting now...\n";
			exit(0);
		}
		else if (cmd.compare("ADD") == 0) {
			book.addContact();
		}
		else if (cmd.compare("SEARCH") == 0) {
			book.searchContact();
		}
		else if (cmd.compare("EXIT") == 0) {
			break ;
		}
	}
}