#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: must be one argument" << std::endl;
		return 1;
	}

	try
	{
		RPN rpn(av[1]);
		int result = rpn.calculate();
		std::cout << result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}