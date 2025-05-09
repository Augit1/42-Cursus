/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:20:32 by aude-la-          #+#    #+#             */
/*   Updated: 2024/11/06 16:30:38 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie*	heapZombie = newZombie("Heeeaaap");
	heapZombie->announce();
	delete heapZombie;
	randomChump("Staaack");
	return (0);
}
