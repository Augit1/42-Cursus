/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:26 by aude-la-          #+#    #+#             */
/*   Updated: 2024/11/27 16:57:41 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{

	Brain originalBrain;
	originalBrain.setIdea(0, "Inicial");
	Brain copiedBrain = originalBrain;
	std::cout << "* Original: " << originalBrain.getIdea(0) << std::endl;
	std::cout << "* Copied  : " << copiedBrain.getIdea(0) << std::endl;
	originalBrain.setIdea(0, "Modificada");
	std::cout << "* Original: " << originalBrain.getIdea(0) << std::endl;
	std::cout << "* Copied  : " << copiedBrain.getIdea(0) << std::endl;
	
	std::cout << "----------------------------" << std::endl;

	Animal* nullAnimal = NULL;

	std::cout << "Testing behavior with a null pointer:" << std::endl;
	if (nullAnimal)
		nullAnimal->makeSound();
	else
		std::cout << "nullAnimal is a null pointer." << std::endl;

	std::cout << "----------------------------" << std::endl;

    const Animal* animals[6];

    for (int i = 0; i < 3; ++i) {
        animals[i] = new Dog();
    }
    for (int i = 3; i < 6; ++i) {
        animals[i] = new Cat();
    }

    for (int i = 0; i < 6; ++i) {
        animals[i]->makeSound();
    }

	std::cout << "----------------------------" << std::endl;
	
	std::cout << "\nTest deep copy..." << std::endl;
	Dog dog1;
	dog1.makeSound();

	Dog dog2 = dog1; // Test du constructeur par copie
	dog2.makeSound();

	Dog dog3;
	dog3 = dog1; // Test de l'opérateur d'affectation
	dog3.makeSound();
	
	std::cout << "----------------------------" << std::endl;

	Dog basic;
	{
		Dog tmp = basic;
	}
	
	std::cout << "----------------------------" << std::endl;

	for (int i = 0; i < 6; ++i) {
        delete animals[i];
    }

	std::cout << "----------------------------" << std::endl;
	
	return 0;
}
