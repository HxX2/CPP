#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	std::list<int> lst;
	std::deque<int> dq;

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
		lst.push_back(i);
		dq.push_back(i);
	}

	try
	{
		std::cout << *easyfind(vec, 5) << std::endl;
		std::cout << *easyfind(lst, 5) << std::endl;
		std::cout << *easyfind(dq, 5) << std::endl;
		std::cout << *easyfind(lst, 10) << std::endl;
	}
	catch (const char *e)
	{
		std::cerr << e << std::endl;
	}

	return 0;
}