#include "Span.hpp"

int main()
{
	Span sp = Span(6);
	std::vector<unsigned int> vec;

	sp.addNumber(1);
	vec.push_back(3);
	vec.push_back(9);
	vec.push_back(12);
	vec.push_back(14);
	vec.push_back(9999);

	sp.addMulti(vec);

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	try
	{
		sp.addNumber(123);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    std::srand(static_cast<unsigned int>(time(0)));
    Span span = Span(10000);
    for (size_t i = 0; i < 10000; ++i)
	{
        // Generate a random value between 0 and UINT_MAX
        unsigned int randomValue = static_cast<unsigned int>(std::rand());
        span.addNumber(randomValue);
    }
    std::cout << "10k value shortest span: "<< span.shortestSpan() << std::endl;
	std::cout << "10k balue longest span: "<< span.longestSpan() << std::endl;
}