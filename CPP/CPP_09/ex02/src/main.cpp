#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>

int	main(int argc, char **argv)
{
	try
	{
		PmergeMe	merge;
		if (argc < 2) throw std::invalid_argument("No arguments provided!");
		for (size_t i = 1; argv[i]; ++i)
		{
			long	num;
			std::istringstream	ss(argv[i]);
			ss >> num;
			if (ss.fail() || !ss.eof() || num < 0) throw std::invalid_argument("Not a positive number!");
			merge._vec.push_back(num);
		}
		merge._deq.assign(merge._vec.begin(), merge._vec.end());
		if (merge._deq.empty()) throw std::runtime_error("Fail to copy.");
		std::cout << "Before:	";
		for (std::vector<unsigned int>::const_iterator it = merge._vec.begin();
				it != merge._vec.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		
		double	vecSortTime = merge.sortVector();
		double	deqSortTime = merge.sortDeque();
//		double	vecSortTime = merge.sortContainer(merge._vec);
//		double	deqSortTime = merge.sortContainer(merge._deq);

		std::cout << "After vector:	";
		for (std::vector<unsigned int>::const_iterator it = merge._vec.begin();
				it != merge._vec.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "After deque:	";
		for (std::deque<unsigned int>::const_iterator it = merge._deq.begin();
				it != merge._deq.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		
		std::cout <<"Time to process a range of " << merge._vec.size()
			<< " elements with std::vector : " << vecSortTime << " us" << std::endl;
		std::cout <<"Time to process a range of " << merge._deq.size()
			<< " elements with std::deque  : " << deqSortTime << " us" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
