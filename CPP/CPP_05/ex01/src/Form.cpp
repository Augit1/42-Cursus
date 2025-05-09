/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:56:01 by aude-la-          #+#    #+#             */
/*   Updated: 2024/12/11 14:03:59 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Form"), signGrade(150), executeGrade(150), isSigned(false)
{
	std::cout << "Form by default created." << std::endl;
}

Form::Form(const std::string& name, int signGrade, int executeGrade)
	: name(name), signGrade(signGrade), executeGrade(executeGrade), isSigned(false)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	: name(other.name), signGrade(other.signGrade),
	executeGrade(other.executeGrade), isSigned(other.isSigned)
{
	std::cout << "Form copied." << std::endl;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	std::cout << "Form assigned." << std::endl;
	return *this;
}

Form::~Form()
{
	std::cout << "Form destroyed." << std::endl;
}

std::ostream&	operator<<(std::ostream& out, const Form& form)
{
	out << form.getName() 
		<< ", sign grade " << form.getSignGrade()
		<< ", execute grade " << form.getExecuteGrade()
		<< ", is signed " << (form.getIsSigned() ? "yes" : "no");
	return out;
}

std::string	Form::getName() const
{
	return name;
}

int	Form::getSignGrade() const
{
	return signGrade;
}

int	Form::getExecuteGrade() const
{
	return executeGrade;
}

bool	Form::getIsSigned() const
{
	return isSigned;
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "Too much skills for this job!";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "You can't be that stupid!";
}
