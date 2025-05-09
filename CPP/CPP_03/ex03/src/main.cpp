/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:50:49 by aude-la-          #+#    #+#             */
/*   Updated: 2024/11/28 17:27:58 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main( void )
{
	DiamondTrap	diamond("Diamondy");
//	diamond.attack("target1");
//	diamond.takeDamage(20);
//	diamond.beRepaired(10);
//
//	diamond.whoAmI();

	diamond.print();

	std::cout << "-----------------------" << std::endl;

	return 0;
}
