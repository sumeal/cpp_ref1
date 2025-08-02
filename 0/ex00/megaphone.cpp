#include <iostream>

int main(int argc, char **argv) {

	int i = 0;
	int j = 1;
	if (argc >= 2)
	{
		while (j < argc)
		{
			i = 0;
			while (argv[j][i])
			{
				if (argv[j][i] >= 'a' && argv[j][i] <= 'z')
					std::cout << (unsigned char) (argv[j][i] - 32);
				else
					std::cout << argv[j][i];
				i++;
			}
			j++;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}