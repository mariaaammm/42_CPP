#include "Span.hpp"

Span::Span(){_maxSize = 0; //std::cout << "Default constructor called" << std::endl;
}

Span::Span(unsigned int N)
{   
    _maxSize = N;
    numbers.reserve(N);
    // std::cout << "Parameter constructor called" << std::endl;
}

Span::Span(const Span &copy)
{
    _maxSize = copy._maxSize;
    numbers = copy.numbers;
    // std::cout << "Copy constructor called" << std::endl;
}

Span& Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        numbers = other.numbers;
    }
    // std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

Span::~Span() {// std::cout << "Destructor called" << std::endl;
}

const char	*Span::Error::what() const throw() 
{ 
	return ("Error");
}

void Span::addNumber(int num)
{
    if (numbers.size() >= _maxSize)
        throw std::range_error("Error");
    numbers.push_back(num);
}

int Span::shortestSpan()
{
    if (numbers.size() < 2)
        throw std::range_error("Failed shortest long span");
    std::sort(numbers.begin(), numbers.end());
    int shortest = INT_MAX;
    for (size_t i = 1; i < numbers.size(); ++i) {
        shortest = std::min(shortest, numbers[i] - numbers[i - 1]);
    }
    return (shortest);
}

int Span::longestSpan()
{
    if (numbers.size() < 2)
        throw std::range_error("Failed finding long span");
    std::sort(numbers.begin(), numbers.end());
    return (numbers.back() - numbers.front());
}


void Span::print() {
    for (size_t i = 0; i < numbers.size(); i++)
    {
        std::cout << numbers[i] << ", ";
    }
};