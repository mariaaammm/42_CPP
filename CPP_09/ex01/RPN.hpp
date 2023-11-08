#pragma once
#include <iostream>
#include <stack>
#include <cstdlib>

class RPN
{
    public:
        RPN();
        RPN(const RPN &copy);
        RPN& operator=(const RPN &other);
        ~RPN();
        void reversePolishNotation(const std::string &arg);
        int getRes() const;
    private:
        std::stack<int> m_stack;
        void Arithmetic(int n1, int n2, char c);
        int _res;
};

std::ostream&	operator<<(std::ostream& o, const RPN& i);