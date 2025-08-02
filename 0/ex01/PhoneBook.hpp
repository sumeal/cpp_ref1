#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private :
		Contact contacts[8];
		int total;
		int index;
	public :
	PhoneBook();
	void addContact();
	void searchContact();
	void displayAll();
};

#endif