#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	{
		Bureaucrat hamid("Hamid", 4);
		PresidentialPardonForm form("Farid");

		hamid.signForm(form);
		hamid.executeForm(form);
	}
	std::cout << std::endl;
	{
		Bureaucrat farid("Farid", 75);
		ShrubberyCreationForm form("Khalid");

		farid.signForm(form);
		farid.executeForm(form);
	}
	std::cout << std::endl;
	{
		Bureaucrat khalid("Khalid", 44);
		RobotomyRequestForm form("Hamid");

		khalid.signForm(form);
		khalid.executeForm(form);
	}

	return (0);
}