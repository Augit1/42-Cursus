/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:26 by aude-la-          #+#    #+#             */
/*   Updated: 2024/11/26 18:37:47 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	Animal* nullAnimal = NULL;

	std::cout << "Testing behavior with a null pointer:" << std::endl;
	if (nullAnimal)
		nullAnimal->makeSound();
	else
		std::cout << "nullAnimal is a null pointer." << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();



	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	
	i->makeSound();
	j->makeSound();
	
	
	delete meta;
	delete j;
	delete i;

	//Wrong:
	std::cout << "-----------------------Wrong-------------------------" << std::endl;
	
	WrongCat	wrongCat;
	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* wi = new WrongCat();

	std::cout << wmeta->getType() << " " << std::endl;
	std::cout << wi->getType() << " " << std::endl;

	wrongCat.makeSound();
	wmeta->makeSound();
	wi->makeSound();

	delete wmeta;
	delete wi;

	std::cout << "-----------------------------------------------------" << std::endl;
	/*******************************************/

	return 0;
}
