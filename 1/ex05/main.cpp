#include "Harl.hpp"

int main() {
	Harl* person = new Harl();

	person->complain("DEBUG");
	person->complain("INFO");
	person->complain("WARNING");
	person->complain("ERROR");
	delete person;
	return 0;

}