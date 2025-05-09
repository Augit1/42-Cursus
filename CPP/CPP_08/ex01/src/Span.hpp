#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>
# include <algorithm>
# include <iterator>
# include <limits>

class Span
{
	private:
		std::vector<int> _vec;
		unsigned int	_maxSize;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span&	operator=(const Span& other);
		~Span();

		void	addNumber(int n);
		
		template <typename Iterator>
		void	addNumbers(Iterator begin, Iterator end)
		{
			if (std::distance(begin, end) > static_cast<int>(_maxSize - _vec.size())) 
				throw std::out_of_range("Span is already full.");
			_vec.insert(_vec.end(), begin, end);
		}

		int		shortestSpan()	const;
		int		longestSpan()	const;
};

#endif // SPAN_HPP
