#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat hamid("Hamid", 75);
	Form leet_form("1337's Form", 70, 85);

	try
	{
		hamid.signForm(leet_form);
		std::cout << hamid << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "🛑 Exception: " << e.what() << std::endl;
	}
	std::cout << leet_form << std::endl;
	return (0);
}