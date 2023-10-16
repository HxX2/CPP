#include "Base.hpp"
#include "Drived.hpp"

Base *generate(void)
{
	std::srand(std::time(NULL));
	int i = std::rand() % 3;
	if (i == 0)
		return (dynamic_cast<Base *>(new A));
	else if (i == 1)
		return (dynamic_cast<Base *>(new B));
	else
		return (dynamic_cast<Base *>(new C));
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch (std::exception &e)
		{
			try
			{
				C &c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << "Error: " << e.what() << std::endl;
			}
		}
	}
}