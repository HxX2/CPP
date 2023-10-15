#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	{
		Bureaucrat hamid("Hamid", 4);
		PresidentialPardonForm form("Idara");

		hamid.signForm(form);
		form.execute(hamid);
	}
	std::cout << std::endl;
	{
		Bureaucrat Farid("Farid", 75);
		ShrubberyCreationForm form("Zira3a");

		Farid.signForm(form);
		form.execute(Farid);
	}
	std::cout << std::endl;
	{
		Bureaucrat khalid("Khalid", 44);
		RobotomyRequestForm form("Sina3a");

		khalid.signForm(form);
		form.execute(khalid);
	}

	return (0);
}