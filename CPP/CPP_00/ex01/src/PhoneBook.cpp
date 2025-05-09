/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augustindelabrosse <aude-la-@student.42ma  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:51:01 by augustindelab     #+#    #+#             */
/*   Updated: 2024/11/05 17:32:40 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0) {}

void	PhoneBook::addContact()
{
	Contact newContact;
	std::string	input;
	bool valid = false;

	do {
		std::cout << "Enter First Name: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "First Name cannot be empty." << std::endl;
	} while (input.empty());
	newContact.setFirstName(input);
	do {
		std::cout << "Enter Last Name: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "Last Name cannot be empty." << std::endl;
	} while (input.empty());
	newContact.setLastName(input);
	do {
		std::cout << "Enter Nickname: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "Nickname: cannot be empty." << std::endl;
	} while (input.empty());
	newContact.setNickname(input);
	do {
		std::cout << "Enter Phone Number: ";
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "Phone Number: cannot be empty." << std::endl;
			continue ;
		}
		if (input.find_first_not_of("0123456789") != std::string::npos)
		{
			std::cout << "Phone Number must contain only digits." << std::endl;
			continue ;
		}
		valid = true;
	} while (!valid);
	newContact.setPhoneNumber(input);
	do {
		std::cout << "Enter Darkest Secret: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "Darkest Secret: cannot be empty." << std::endl;
	} while (input.empty());
	newContact.setDarkestSecret(input);

	if (contactCount < 8)
	{
		contacts[contactCount] = newContact;
		contactCount++;
	}
	else
	{
		for (int i = 0; i < 7; i++)
			contacts[i] = contacts[i + 1];
		contacts[7] = newContact;
	}
	std::cout << "Contact added successfully!" << std::endl;
}

int	PhoneBook::readValidIndex() const
{
    std::string input;
    int index = -1;
    bool valid = false;

    while (!valid)
	{
        std::cout << "Enter the index of the contact you want to display: ";
        std::getline(std::cin, input);

        if (input.empty()) 
		{
            std::cout << "Index cannot be empty!" << std::endl;
            continue;
        }

        std::stringstream ss(input);
        if (!(ss >> index)) 
		{
            std::cout << "Invalid index! Please enter a valid number." << std::endl;
            continue;
        }

        char remaining;
        if (ss >> remaining) 
		{
            std::cout << "Invalid input! Please enter only an integer." << std::endl;
            continue;
        }
		index--;
        if (index < 0 || index >= contactCount) 
		{
            std::cout << "Invalid index! Please enter an index between 1 and " << contactCount << "." << std::endl;
            continue;
        }

        valid = true;
    }
	return (index);
}

void PhoneBook::searchContact() const 
{
    if (contactCount == 0)
	{
        std::cout << "No contacts available." << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < contactCount; ++i)
	{
        std::cout << std::setw(10) << i + 1 << "|";
        displayContactInfo(contacts[i].getFirstName());
        std::cout << "|";
        displayContactInfo(contacts[i].getLastName());
        std::cout << "|";
        displayContactInfo(contacts[i].getNickname());
        std::cout << std::endl;
    }
    int index = readValidIndex();
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

void	PhoneBook::displayContactInfo(const std::string& info) const
{
	if (info.length() > 10)
		std::cout << info.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << info;
}
