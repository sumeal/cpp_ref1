#ifndef SERIALIZER_HPP
 #define SERIALIZER_HPP

 #include <stdint.h>
 #include <iostream>

struct Data
{
	int data;
};

class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	private:
		Serializer();
		~Serializer();
		Serializer(Serializer &other);
		Serializer& operator=(Serializer const &other);
};

#endif