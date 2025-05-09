#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>
class Array
{
	private:
		T	*data;
		unsigned int	len;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array&	operator=(const Array& other);
		~Array();

		unsigned int	size()	const;
		T&			operator[](unsigned int index);
		const T&	operator[](unsigned int index)	const;
};

# include "Array.tpp"

#endif // ARRAY_HPP
