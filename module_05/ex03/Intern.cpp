#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &src)
{
	(void)src;
}

Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	return (*this);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	AForm *form = NULL;

	switch (formName[0])
	{
	case 'p':
		if (formName != "presidential pardon")
			break;
		std::cout << "Intern creates " << formName << std::endl;
		form = new PresidentialPardonForm(target);
		break;
	case 'r':
		if (formName != "robotomy request")
			break;
		std::cout << "Intern creates " << formName << std::endl;
		form = new RobotomyRequestForm(target);
		break;
	case 's':
		if (formName != "shrubbery creation")
			break;
		std::cout << "Intern creates " << formName << std::endl;
		form = new ShrubberyCreationForm(target);
		break;
	default:
		std::cout << "Error: Invalid form name" << std::endl;
		break;
	}
	return (form);
}
