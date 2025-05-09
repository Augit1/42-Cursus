/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:56:01 by aude-la-          #+#    #+#             */
/*   Updated: 2024/11/27 16:13:08 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal created." << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "Animal copied." << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
		type = other.type;
	std::cout << "Animal assigned." << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destroyed." << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Animal makes sound." << std::endl;
}

std::string	Animal::getType() const
{
	return type;
}
