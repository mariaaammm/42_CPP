#include "Serializer.hpp"

int main()
{
	Data *a = new(Data);

	a->grade = 10;
	a->message = "Hello";
	std::cout << a->grade << std::endl;
	std::cout << a->message << std::endl;
	std::cout << std::endl;

	std::cout << a << std::endl;
	uintptr_t	n = Serializer::serialize(a);
	std::cout << n << std::endl;

	std::cout << n << std::endl;
	Data	*b = Serializer::deserialize(n);
	std::cout << b << std::endl;

	delete (b);
	return (0);
}