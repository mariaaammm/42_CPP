#include "RPN.hpp"

int	main(int argc, char **argv)
{
	RPN	rpn;

	if (argc != 2)
	{
		std::cerr << "Error: enter 1 argument" << std::endl;
		return (-1);
	}
	else
	{
		try
		{
			rpn.reversePolishNotation(argv[1]);
			std::cout << rpn << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
