#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

 #include <string>
 #include <ctype.h>
 #include <algorithm>
 #include <iostream>
 #include <climits>
 #include <cmath>
 #include <cerrno>
 #include <cfloat>


 enum {
	CHAR = 1,
	INT = 2,
	FLOAT = 3,
	DOUBLE = 4,
	ERROR = 5,
 };

class ScalarConverter
{
	public:
		static void	convert(std::string input);
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
};

#endif