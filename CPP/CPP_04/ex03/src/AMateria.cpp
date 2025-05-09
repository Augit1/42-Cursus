/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:56:01 by aude-la-          #+#    #+#             */
/*   Updated: 2024/11/27 16:24:04 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type("default") {}

AMateria::AMateria(std::string const& type) : type(type) {}

AMateria&	AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		type = other.type;
	return *this;
}

AMateria::~AMateria() {}

std::string const&	AMateria::getType() const
{
	return type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* uses materia on " << target.getName() << " *" << std::endl;
}
