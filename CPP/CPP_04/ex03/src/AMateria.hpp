/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:51:37 by aude-la-          #+#    #+#             */
/*   Updated: 2024/11/27 16:18:27 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

class	ICharacter;

class	AMateria
{
	protected:
		std::string	type;
	
	public:
		AMateria();
		AMateria(std::string const& type);
		AMateria&	operator=(const AMateria& other);
		virtual	~AMateria();

		std::string	const& getType() const;
		virtual	AMateria*	clone() const = 0;
		virtual	void	use(ICharacter& target);
};

#endif
