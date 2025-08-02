#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Constructor Called\n";
}

Brain::~Brain() {
	std::cout << "Brain Destructor Called\n";
}

Brain::Brain(Brain& other) {
	std::cout << "Brain Copy Constructor Called\n";
    for (int i = 0; i < 100; ++i) {
        this->ideas[i] = other.ideas[i];
	}
}

void Brain::setIdea(int i, std::string idea) {
	this->ideas[i] = idea;
}

std::string Brain::getIdea(int i) {
	return this->ideas[i];
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain Assignment Operator Called\n";
    for (int i = 0; i < 100; ++i) {
        this->ideas[i] = other.ideas[i];
	}
	return *this;
}
