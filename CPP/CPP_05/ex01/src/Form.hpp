/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:39:23 by aude-la-          #+#    #+#             */
/*   Updated: 2024/12/11 14:03:17 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		const int			signGrade;
		const int			executeGrade;
		bool				isSigned;

	public:
		Form();
		Form(const std::string& name, int signGrade, int executeGrade);
		Form(const Form& other);
		Form&	operator=(const Form& other);
		~Form();

		std::string	getName() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;
		bool		getIsSigned() const;
	
		void	beSigned(const Bureaucrat& b);

		friend std::ostream&	operator<<(std::ostream& out, const Form& form);
	
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif
