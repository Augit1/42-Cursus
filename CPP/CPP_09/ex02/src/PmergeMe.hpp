#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <vector>
# include <deque>
# include <ctime>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);
		~PmergeMe();

		std::vector<unsigned int>	_vec;
		std::deque<unsigned int>	_deq;

		double	sortVector();
		double	sortDeque();
};

#endif // PMERGEME_HPP
