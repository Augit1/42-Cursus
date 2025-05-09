#include "AForm.hpp"

AForm::AForm() : name("AForm"), signGrade(150), executeGrade(150), isSigned(false)
{
	std::cout << "AForm by default created." << std::endl;
}

AForm::AForm(const std::string& name, int signGrade, int executeGrade)
	: name(name), signGrade(signGrade), executeGrade(executeGrade), isSigned(false)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: name(other.name), signGrade(other.signGrade), executeGrade(other.executeGrade), isSigned(other.isSigned) 
{
	std::cout << "AForm copied." << std::endl;
}

AForm&	AForm::operator=(const AForm& other)
{
	if (this != &other)
		isSigned = other.isSigned;
	std::cout << "AForm assigned." << std::endl;
	return *this;
}

AForm::~AForm() {}

std::string	AForm::getName() const { return name; }
int	AForm::getSignGrade() const { return signGrade; }
int	AForm::getExecuteGrade() const { return executeGrade; }
bool	AForm::getIsSigned() const { return isSigned; }

void	AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > signGrade)
		throw GradeTooHighException();
	isSigned = true;
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return "Form not signed!";
}

std::ostream&	operator<<(std::ostream& out, const AForm& form)
{
	out << "Form " << form.getName() << ": "
		<< (form.getIsSigned() ? "Signed" : "Not signed")
		<< ", Sign Grade " << form.getSignGrade()
		<< ", Execute Grade " << form.getExecuteGrade();
	return out;
}
