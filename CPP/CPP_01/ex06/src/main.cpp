/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:42:52 by aude-la-          #+#    #+#             */
/*   Updated: 2024/11/07 16:34:20 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Harl.hpp"

enum LogLevel { DEBUG = 0, INFO, WARNING, ERROR, INVALID };

LogLevel getLogLevel(std::string level)
{
	if (level == "DEBUG") return (DEBUG);
	if (level == "INFO") return (INFO);
	if (level == "WARNING") return (WARNING);
	if (level == "ERROR") return (ERROR);
	return (INVALID);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "You need to precise the level you want filter." << std::endl, 1);
	Harl	harl;
	LogLevel level = getLogLevel(argv[1]);
	
	switch (level)
	{
		case DEBUG:
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("DEBUG");
			/* fall-through */
		case INFO:
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("INFO");
			/* fall-through */
		case WARNING:
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("WARNING");
			/* fall-through */
		case ERROR:
			std::cout << "[ ERROR ]" << std::endl;
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}
