#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) : _vec(other._vec), _maxSize(other._maxSize) {}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_vec = other._vec;
	}
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int n)
{
	if (_vec.size() >= _maxSize)
		throw std::out_of_range("Span is already full.");
	_vec.push_back(n);
}

int	Span::shortestSpan() const
{
	if (_vec.size() < 2)
		throw std::logic_error("Not enough elements to calculate a span.");
	std::vector<int>	sorted(_vec);
	std::sort(sorted.begin(), sorted.end());

	int	shortest = std::numeric_limits<int>::max();
	for (std::vector<int>::size_type i = 1; i < sorted.size(); ++i)
	{
		int	diff = sorted[i] - sorted[i - 1];
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

int	Span::longestSpan() const
{
	if (_vec.size() < 2)
		throw std::logic_error("Not enough elements to calculate a span.");
	int	min = *std::min_element(_vec.begin(), _vec.end());
	int	max = *std::max_element(_vec.begin(), _vec.end());
	return max - min;
}
