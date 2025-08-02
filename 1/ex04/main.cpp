#include <iostream>
#include <sstream>
#include <fstream>

int main(int argc, char **argv) 
{
	if (argc != 4) {
		std::cout << "Format : ./replace filename string1 string2" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream infile(filename.c_str());
	if (!infile) {
		std::cout << "Error opening file" << std::endl;
		return 1;
	}

	if (s1.empty()) {
		std::cout << "Error: s1 is empty\n";
		return 1;
	}

	std::stringstream buffer;
	buffer << infile.rdbuf();
	std::string content = buffer.str();
	infile.close();
	size_t i = 0;
	while (true) {
		i = content.find(s1, i);
		if (i == std::string::npos)
			break;
		content.replace(i, s1.length(), s2);
		i += s2.length();

	}
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile) {
		std::cout << "Error opening output file\n";
		return 1;
	}
	outfile << content;
	outfile.close();

	return 0;
}