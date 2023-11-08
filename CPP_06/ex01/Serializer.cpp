#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &)
{
    std::cout << "Copy constructor called" << std::endl;
}

Serializer& Serializer::operator=(const Serializer &)
{
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

Serializer::~Serializer()
{
    std::cout << "Destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t	res = reinterpret_cast<uintptr_t>(ptr);
	return (res);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *res = reinterpret_cast<Data *>(raw);
	return (res);
}