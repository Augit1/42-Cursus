#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
    Data myData = {42, "Hello, World!"};

    uintptr_t serialized = Serializer::serialize(&myData);
    std::cout << "Serialized value: " << serialized << std::endl;
    
	Data* deserialized = Serializer::deserialize(serialized);

    if (deserialized == &myData)
	{
        std::cout << "Deserialization successful!" << std::endl;
        std::cout << "Data: { id: " << deserialized->id
                  << ", name: \"" << deserialized->name << "\" }" << std::endl;
    }
	else
        std::cout << "Deserialization failed!" << std::endl;

    return 0;
}
