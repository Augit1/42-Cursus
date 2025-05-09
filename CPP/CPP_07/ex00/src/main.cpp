#include "whatever.hpp"
#include <iostream>

int	main()
{
	int	ia(5);
	int	ib(-4);
	double	da(3.43);
	double	db(12.323);
	char	ca('e');
	char	cb('a');

	std::cout << "ia: " << ia << "\tib: " << ib << std::endl;
	swap(ia, ib);
	std::cout << "ia: " << ia << "\tib: " << ib << std::endl;
	
	std::cout << "min: " << min(ia, ib) << std::endl;
	std::cout << "max: " << max(ia, ib) << std::endl;

	std::cout << "min: " << min(da, db) << std::endl;
	std::cout << "max: " << max(da, db) << std::endl;

	std::cout << "min: " << min(ca, cb) << std::endl;
	std::cout << "max: " << max(ca, cb) << std::endl;

	std::cout << "----------------------------------------------------" << std::endl;

	int a = 2;
	int b = 3;
	
	::swap( a, b );
	
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";
	
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	
	return 0;
}
