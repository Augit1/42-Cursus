/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:51:37 by aude-la-          #+#    #+#             */
/*   Updated: 2025/01/17 16:24:02 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	private:
		const std::string	name;
		const int			signGrade;
		const int			executeGrade;
		bool				isSigned;
	
	public:
		AForm();
		AForm(const std::string& name, int signGrade, int executeGrade);
		AForm(const AForm& other);
		AForm&	operator=(const AForm& other);
		virtual	~AForm();

		std::string	getName() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;
		bool		getIsSigned() const;
		

		void	beSigned(const Bureaucrat& b);
		virtual void	execute(const Bureaucrat& executor) const = 0;
	
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

		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
