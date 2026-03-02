#ifndef SPAN_HPP
 #define SPAN_HPP

  #include <exception>
  #include <vector>
  #include <algorithm>
  #include <iostream>
  #include <ctime>

class SpanFullException : public std::exception
{
	const char* what() const throw();
};

class SpanEmptyException : public std::exception
{
	const char* what() const throw();
};

class Span
{
	public:
		Span();
		Span(unsigned int size);
		~Span();
		Span(const Span& other);
		Span& operator=(const Span &other);
		void addNumber(unsigned int new_num);
		void addMulti(std::vector<unsigned int>num_vec);
		int shortestSpan();
		int longestSpan();
		unsigned int getN() const;
		void setN(unsigned int newN);

	private:
		unsigned int _N;
		std::vector<unsigned int> _vec;

};

#endif