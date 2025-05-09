#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T>
void	iter(T *tab, size_t length, void (*func)(T &))
{
	for (size_t i = 0; i < length; ++i)
		func(tab[i]);
}

#endif
