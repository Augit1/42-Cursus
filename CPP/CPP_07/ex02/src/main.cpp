#include <iostream>
#include "Array.hpp"

int main()
{
    try {
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;

        Array<int> intArray(5);
        std::cout << "intArray size: " << intArray.size() << std::endl;

        for (unsigned int i = 0; i < intArray.size(); i++)
            intArray[i] = i * 10;

        std::cout << "intArray elements: ";
        for (unsigned int i = 0; i < intArray.size(); i++) 
            std::cout << intArray[i] << " ";
        std::cout << std::endl;

        Array<int> copyArray = intArray;
        copyArray[0] = 999;
        std::cout << "Modified copyArray[0]: " << copyArray[0] << std::endl;
        std::cout << "Original intArray[0]: " << intArray[0] << std::endl;

        std::cout << "Accessing out-of-bounds index: " << std::endl;
        std::cout << intArray[10] << std::endl; // Doit lancer une exception
    }
	catch (const std::exception &e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
