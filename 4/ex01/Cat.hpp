#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	public :
		Cat();
		~Cat();
		Cat(Cat& other);
		Cat& operator=(const Cat&other);
		void makeSound() const;
		Brain* getBrain() const;
	private :
		Brain* brain;
};

class WrongCat : public WrongAnimal {
	public :
		WrongCat();
		~WrongCat();
		WrongCat(WrongCat& other);
		WrongCat& operator=(const WrongCat& other);
		void makeSound() const;
};

#endif