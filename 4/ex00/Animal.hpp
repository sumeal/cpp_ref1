#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal {
	protected :
		std::string type;
	public :
		Animal();
		virtual ~Animal();
		Animal(Animal& other);
		Animal& operator=(const Animal& other);
		const std::string getType() const;
		virtual void makeSound() const;
};

class WrongAnimal {
	protected :
		std::string type;
	public :
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		void makeSound() const;
		const std::string getType() const;
};

#endif