/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:26 by aude-la-          #+#    #+#             */
/*   Updated: 2024/11/27 17:03:00 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int	main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	
	AMateria*	tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;

	std::cout << "-----------Limits--------------" << std::endl;

	Character tester("Tester");
    tester.equip(new Ice());
    tester.equip(new Cure());
    tester.equip(new Ice());
    tester.equip(new Cure());

    AMateria* extraMateria = new Ice();
	tester.equip(extraMateria); //ignored
    
	tester.use(0, tester);
    tester.use(3, tester);
    tester.use(4, tester);

    delete extraMateria;
	
	std::cout << "-------------------------------" << std::endl;

	return 0;
}
