#include <iostream>
#include "Span.hpp"

int	main()
{
	try
	{
		Span mySpace(5);
        mySpace.addNumber(6);
        mySpace.addNumber(3);
        mySpace.addNumber(17);
        mySpace.addNumber(9);
        mySpace.addNumber(11);

        std::cout << "Shortest Span: " << mySpace.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << mySpace.longestSpan() << std::endl;

        std::vector<int> numbers;
        for (int i = 0; i < 10000; ++i) {
            numbers.push_back(i);
        }

        Span bigSpan(10000);
        bigSpan.addNumbers(numbers.begin(), numbers.end());
        std::cout << "Shortest Span (big span): " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span (big span): " << bigSpan.longestSpan() << std::endl;
        
		std::cout << "------------------------------------------------------" << std::endl;

		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} 
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
