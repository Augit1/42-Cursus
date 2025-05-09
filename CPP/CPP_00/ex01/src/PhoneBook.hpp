/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augustindelabrosse <aude-la-@student.42ma  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:50:55 by augustindelab     #+#    #+#             */
/*   Updated: 2024/11/05 17:06:23 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int	contactCount;
	public:
		PhoneBook();
		void	addContact();
		void	searchContact() const;
		int		readValidIndex() const;
		void	displayContactInfo(const std::string& info) const;
};

#endif
