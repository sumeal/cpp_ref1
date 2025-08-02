#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>


class Brain {
	public :
		std::string ideas[100];
		Brain();
		~Brain();
		Brain(Brain& other);
		Brain& operator=(const Brain& other);
		void setIdea(int i, std::string idea);
		std::string getIdea(int i);
};

#endif