#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./btc [filename]" << std::endl;
		return 1;
	}

	BitcoinExchange exchange(av[1]);
	exchange.run();

	return 0;
}
