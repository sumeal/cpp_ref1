#include "Serializer.hpp"

int main()
{
	Data test;
	test.data = 42;

	std::cout << "Before serialize address: " << std::endl;
	std::cout << &test << std::endl << std::endl;
	uintptr_t after_serialize = Serializer::serialize(&test);
	//std::cout << after_serialize << std::endl;
	Data* after_deserialize = Serializer::deserialize(after_serialize);
	std::cout << "After deserialize address: " << std::endl;
	std::cout << after_deserialize << std::endl << std::endl;
	std::cout << after_deserialize->data << std::endl;

	return (0);
}