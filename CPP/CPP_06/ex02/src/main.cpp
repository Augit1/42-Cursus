#include "Base.hpp"

int main()
{
    Base* randomObject = generate();
    std::cout << "Using pointer: ";
    identify(randomObject);

    std::cout << "Using reference: ";
    identify(*randomObject);

    delete randomObject;
    
	return 0;
}
