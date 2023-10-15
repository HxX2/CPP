#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat hamid("Hamid", 150);

	std::cout << hamid << std::endl;

	try
	{
		hamid.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << "🛑 Exception: " << e.what() << std::endl;
	}

	std::cout << hamid << std::endl;

	try
	{
		hamid.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << "🛑 Exception: " << e.what() << std::endl;
	}

	std::cout << hamid << std::endl;

	return (0);
}