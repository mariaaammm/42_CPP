#include "RPN.hpp"

RPN::RPN() : _res(0) {}

RPN::RPN(const RPN &copy)
{
    m_stack = copy.m_stack;
    _res = copy._res;
}

RPN& RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        this->m_stack = other.m_stack;
        this->_res = other._res;
    }
    return (*this);
}

RPN::~RPN() {}

void RPN::Arithmetic(int n1, int n2, char c)
{
    switch(c)
    {
        case '+':
            m_stack.push(n1 + n2);
            break; 
        case '-':
            m_stack.push(n1 - n2);
            break;
        case '*':
            m_stack.push(n1 * n2);
            break; 
        case '/':
            if (n2 == 0)
                throw std::range_error("No division by 0");
            m_stack.push(n1 / n2);
            break; 
    }
}

void	RPN::reversePolishNotation(const std::string &expr)
{
	std::string token;

	for (size_t i = 0; i < expr.length(); i++)
	{
		char c = expr[i];
		if (c == ' ')
			continue;
		else if (isdigit(c))
		{
			if (expr[i + 1] != ' ')
				throw std::invalid_argument("Error");
			token += c;
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (m_stack.size() < 2)
				throw std::underflow_error("Not enough data");
			int num2 = m_stack.top();
			m_stack.pop();
			int num1 = m_stack.top();
			m_stack.pop();
			Arithmetic(num1, num2, c);
		}
		else
			throw std::invalid_argument("Error");
		if (!token.empty())
		{
			m_stack.push(atoi(token.c_str()));
			token.clear();
		}
	}
	if (m_stack.size() != 1)
		throw std::overflow_error("Error");
	_res = m_stack.top();
	m_stack.pop();
}

int RPN::getRes() const {return (_res);}

std::ostream&	operator<<(std::ostream& o, const RPN& i)
{
	o << i.getRes();
	return (o);
}