#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

double	PmergeMe::sortVector()
{
	if (_vec.size() <= 1) return 0;

	clock_t	start = clock();

	std::vector<unsigned int>	mins, maxs;
	for (size_t i = 0; i < _vec.size(); i += 2)
	{
		if (i + 1 < _vec.size())
		{
			if (_vec[i] < _vec[i + 1])
			{
				mins.push_back(_vec[i]);
				maxs.push_back(_vec[i + 1]);
			}
			else
			{
				mins.push_back(_vec[i + 1]);
				maxs.push_back(_vec[i]);
			}
		}
		else mins.push_back(_vec[i]);
	}

	std::vector<unsigned int>	sortedMins;
	for (size_t i = 0; i < mins.size(); ++i)
	{
		std::vector<unsigned int>::iterator pos = std::lower_bound(sortedMins.begin(), sortedMins.end(), mins[i]);
		sortedMins.insert(pos, mins[i]);
	}

	std::vector<unsigned int>	result;
	size_t	i = 0, j = 0;
	while (i < sortedMins.size() && j < maxs.size())
	{
		if (sortedMins[i] <= maxs[j])
		{
			result.push_back(sortedMins[i]);
			++i;
		}
		else
		{
			result.push_back(maxs[j]);
			++j;
		}
	}
	while (i < sortedMins.size())
	{
		result.push_back(sortedMins[i]);
		++i;
	}
	while (j < maxs.size())
	{
		std::vector<unsigned int>::iterator	pos = std::lower_bound(result.begin(), result.end(), maxs[j]);
		result.insert(pos, maxs[j]);
		++j;
	}
	_vec = result;

	clock_t	end = clock();

	return static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

double	PmergeMe::sortDeque()
{
	if (_deq.size() <= 1) return 0;

	clock_t	start = clock();

	std::deque<unsigned int>	mins, maxs;
	for (size_t i = 0; i < _deq.size(); i += 2)
	{
		if (i + 1 < _deq.size())
		{
			if (_deq[i] < _deq[i + 1])
			{
				mins.push_back(_deq[i]);
				maxs.push_back(_deq[i + 1]);
			}
			else
			{
				mins.push_back(_deq[i + 1]);
				maxs.push_back(_deq[i]);
			}
		}
		else mins.push_back(_deq[i]);
	}

	std::deque<unsigned int>	sortedMins;
	for (size_t i = 0; i < mins.size(); ++i)
	{
		std::deque<unsigned int>::iterator pos = std::lower_bound(sortedMins.begin(), sortedMins.end(), mins[i]);
		sortedMins.insert(pos, mins[i]);
	}

	std::deque<unsigned int>	result;
	size_t	i = 0, j = 0;
	while (i < sortedMins.size() && j < maxs.size())
	{
		if (sortedMins[i] <= maxs[j])
		{
			result.push_back(sortedMins[i]);
			++i;
		}
		else
		{
			result.push_back(maxs[j]);
			++j;
		}
	}
	while (i < sortedMins.size())
	{
		result.push_back(sortedMins[i]);
		++i;
	}
	while (j < maxs.size())
	{
		std::deque<unsigned int>::iterator	pos = std::lower_bound(result.begin(), result.end(), maxs[j]);
		result.insert(pos, maxs[j]);
		++j;
	}
	_deq = result;

	clock_t	end = clock();

	return static_cast<double>(end - start) / CLOCKS_PER_SEC;
}
