#include "Base.hpp"

Base*	generate(void)
{
	srand(static_cast<unsigned int>(time(0)));
	int	randValue = rand() % 3;

	switch (randValue)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" <<std::endl;
		return ;
	} catch (...) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	} catch (...) {}
	
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" <<std::endl;
		return ;
	} catch (...) {}

	std::cout << "Unknown type" << std::endl;
}
