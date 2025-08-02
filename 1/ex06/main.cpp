#include "Harl.hpp"

int main(int argc, char **argv) {
	Harl person;
	int j = -1;

	if (argc != 2) {
		std::cout << "Format : ./harlFilter \"LEVELS\"\n";
		return 1;
	}
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++) {
		if (argv[1] == levels[i]) {
			j = i;
			break;
		}
	}
	switch (j) {
		case 0:
			person.complain("DEBUG");
			// fall through
		case 1:
			person.complain("INFO");
			//fall through
		case 2:
			person.complain("WARNING");
			//fall through
		case 3:
			person.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break;
	}
}