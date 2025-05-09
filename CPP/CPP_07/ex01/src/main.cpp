#include <iostream>
#include "iter.hpp"

void increment(int &x) {
    x++;
}

void toUpperCase(char &c) {
    if (c >= 'a' && c <= 'z') {
        c = c - ('a' - 'A');
    }
}

template <typename T>
void printElement(T &x) {
    std::cout << x << " ";
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original intArray: ";
    iter(intArray, intArraySize, printElement);
    std::cout << std::endl;

    iter(intArray, intArraySize, increment);

    std::cout << "Incremented intArray: ";
    iter(intArray, intArraySize, printElement);
	std::cout << std::endl;

    // Test avec un tableau de caractères
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charArraySize = sizeof(charArray) / sizeof(charArray[0]);

    std::cout << "Original charArray: ";
    iter(charArray, charArraySize, printElement);
    std::cout << std::endl;

    iter(charArray, charArraySize, toUpperCase);

    std::cout << "Uppercase charArray: ";
    iter(charArray, charArraySize, printElement);
    std::cout << std::endl;

    return 0;
}
