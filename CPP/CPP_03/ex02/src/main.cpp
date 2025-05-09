/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:50:49 by aude-la-          #+#    #+#             */
/*   Updated: 2024/11/26 14:26:37 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	ClapTrap	robot("Clappy");
	robot.attack("target1");
	robot.takeDamage(5);
	robot.beRepaired(3);

	std::cout << "-----------------------" << std::endl;
	
	ScavTrap	scav("Scavvy");
	scav.attack("target2");
	scav.takeDamage(20);
	scav.beRepaired(10);
	scav.guardGate();
	
	std::cout << "-----------------------" << std::endl;
	
	FragTrap	frag("Fraggy");
	frag.attack("target3");
	frag.takeDamage(30);
	frag.beRepaired(20);
	frag.highFivesGuys();

	std::cout << "-----------------------" << std::endl;

	return 0;
}
