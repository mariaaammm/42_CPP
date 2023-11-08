#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Span
{
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &copy);
        Span& operator=(const Span &other);
        ~Span();

        class Error : public std::exception
		{
            public:
				 const char* what() const throw();
		};

        void addNumber(int num);
        int shortestSpan();
        int longestSpan();
        template <typename T>
        void addRange(T begin, T end);
        
        void print();
    private:
        unsigned int _maxSize;
        std::vector<int> numbers;
};


template <typename T>
void Span::addRange(T begin, T end) 
{
    while (begin != end) {
        addNumber(*begin);
        ++begin;
    }
}