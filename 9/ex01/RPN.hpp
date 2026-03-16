#ifndef RPN_HPP
 #define RPN_HPP

 #include <iostream>
 #include <string>
 #include <stack>

 class invalidInputException : public std::exception
 {
	public:
		const char *what() const throw()
		{
			return ("Error: invalid RPN\nvalid ex: ./RPN \"2 3 * 8 * 2 / 3 * 8 9 - - 4 -\"");
		}
 };

 class RPN
 {
	private:
		std::stack<int> _stack;

	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		std::stack<int> getStack() const;
		void isInputValid(std::string input);
		void runRPN(std::string input);
		void runOperation(char operation);
		int operate(char operation, int a, int b);
 };

#endif