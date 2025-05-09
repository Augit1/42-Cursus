/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:06:42 by aude-la-          #+#    #+#             */
/*   Updated: 2024/11/07 15:27:03 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

void	Harl::debug()
{
	std::cout << "This is a debugging message." << std::endl;
}

void	Harl::info()
{
	std::cout << "This is an informational message." << std::endl;
}

void	Harl::warning()
{
	std::cout << "This is a warning message." << std::endl;
}

void	Harl::error()
{
	std::cout << "THIS IS AN ERROR !!!!" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	void (Harl::*functions[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	for (int i = 0; i < 4; i++)
		if (levels[i] == level)
			return ((this->*functions[i])());
	std::cout << "Unknown level: " << level << std::endl;
}
