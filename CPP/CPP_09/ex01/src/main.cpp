#include <iostream>
#include "RPN.hpp"

int	main(int argc, char **argv)
{
	try
	{
		if (argc != 2) throw std::invalid_argument("Usage: ./RPN <expression>");
		RPN	solver;
		int	result = solver.calculate(argv[1]);
		std::cout << result << std::endl;
	} 
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
