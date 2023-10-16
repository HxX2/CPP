#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	{
		Bureaucrat hamid("Hamid", 4);
		Intern intern;
		AForm *form = intern.makeForm("presidential pardon", "Khalid");

		if (form)
		{
			hamid.signForm(*form);
			form->execute(hamid);
			delete form;
		}
	}
	std::cout << std::endl;
	{
		Bureaucrat farid("Farid", 75);
		Intern intern;
		AForm *form = intern.makeForm("shrubbery creation", "Hamid");

		if (form)
		{
			farid.signForm(*form);
			form->execute(farid);
			delete form;
		}
	}
	std::cout << std::endl;
	{
		Bureaucrat khalid("Khalid", 44);
		Intern intern;
		AForm *form = intern.makeForm("robotomy request", "Farid");

		if (form)
		{
			khalid.signForm(*form);
			form->execute(khalid);
			delete form;
		}
	}

	return (0);
}