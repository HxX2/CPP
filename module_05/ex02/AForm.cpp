#include "AForm.hpp"

AForm::AForm() : _name("default"), _grade_to_sign(1), _grade_to_execute(1)
{
}

AForm::~AForm()
{
}

AForm::AForm(const AForm &src) : _name(src._name), _grade_to_sign(src._grade_to_sign), _grade_to_execute(src._grade_to_execute)
{
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw AForm::GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw AForm::GradeTooLowException();
}

AForm &AForm::operator=(const AForm &src)
{
	(void)src;
	return (*this);
}

std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getGradeToSign() const
{
	return (_grade_to_sign);
}

int AForm::getGradeToExecute() const
{
	return (_grade_to_execute);
}

std::string AForm::getTarget() const
{
	return(_target);
}

void AForm::setTarget(std::string target)
{
	_target = target;
}

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > _grade_to_sign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!_signed)
		return;
	if (executor.getGrade() > _grade_to_execute)
		throw AForm::GradeTooLowException();
	action();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << f.getName() << " Aform, grade required to sign: " << f.getGradeToSign() << ", grade required to execute: " << f.getGradeToExecute() << ", signed: " << f.getSigned();
	return (out);
}
