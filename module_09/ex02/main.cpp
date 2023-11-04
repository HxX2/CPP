#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 3)
	{
		std::cerr << "Error: must be more than two arguments" << std::endl;
		return 1;
	}

	try
	{
		PmergeMe pmerge(av);
		std::cout << "===============[Vector sort]===============" << std::endl;
		pmerge.vector_sort();
		std::cout << std::endl;
		std::cout << "===============[Deque sort]================" << std::endl;
		pmerge.deque_sort();
	}
	catch(const std::exception& e)
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}
	
	return 0;
}
