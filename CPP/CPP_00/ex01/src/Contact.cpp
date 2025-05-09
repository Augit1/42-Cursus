/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augustindelabrosse <aude-la-@student.42ma  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:51:41 by augustindelab     #+#    #+#             */
/*   Updated: 2024/10/02 18:26:32 by augustindelab    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setFirstName(const std::string& firstName)
{
	this->firstName = firstName;
}

void	Contact::setLastName(const std::string& lastName)
{
	this->lastName = lastName;
}

void	Contact::setNickname(const std::string& nickname)
{
	this->nickname = nickname;
}

void	Contact::setPhoneNumber(const std::string& phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(const std::string& darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const
{
	return this->firstName;
}

std::string Contact::getLastName() const
{
	return this->lastName;
}

std::string Contact::getNickname() const
{
	return this->nickname;
}

std::string Contact::getPhoneNumber() const
{
	return this->phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return this->darkestSecret;
}
