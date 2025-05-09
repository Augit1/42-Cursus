#include "easyfind.hpp"
#include <iostream>
#include <vector>

int	main()
{
	try
	{
		std::vector<int> vec;
		for (int i = 1; i < 10; ++i)
			vec.push_back(i);
		std::vector<int>::const_iterator it = easyfind(vec, 3);
		std::cout << "Found value: " << *it << std::endl;
		
		it = easyfind(vec, 9);
		std::cout << "Found value: " << *it << std::endl;
		
		it = easyfind(vec, 10);
		std::cout << "Found value: " << *it << std::endl;
	} 
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
