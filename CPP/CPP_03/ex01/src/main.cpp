/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:50:49 by aude-la-          #+#    #+#             */
/*   Updated: 2024/11/26 14:00:55 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
	ClapTrap	robot("Clappy");
	robot.attack("target1");
	robot.takeDamage(5);
	robot.beRepaired(3);

	std::cout << "-----------------------" << std::endl;
	
	ScavTrap scav("Scavvy");
	scav.attack("target2");
	scav.takeDamage(20);
	scav.beRepaired(10);
	scav.guardGate();
	
	std::cout << "-----------------------" << std::endl;

	return 0;
}
