#include "iter.hpp"

void print(int &n)
{
	std::cout << n << " ";
}

void add(int &n)
{
	n += 1;
}

void sub(int &n)
{
	n -= 1;
}

void rot13(char &c)
{
	if (c >= 'a' && c <= 'm')
		c += 13;
	else if (c >= 'n' && c <= 'z')
		c -= 13;
	else if (c >= 'A' && c <= 'M')
		c += 13;
	else if (c >= 'N' && c <= 'Z')
		c -= 13;
}

int main()
{
	{
		int arr[] = {1, 2, 3, 4, 5};

		iter(arr, 5, &add);
		iter(arr, 5, &print);
		std::cout << std::endl;

		iter(arr, 5, &sub);
		iter(arr, 5, &print);
		std::cout << std::endl;
	}
	{
		char str[26] = "Sonic sound in the house.";

		iter(str, std::strlen(str), &rot13);
		std::cout << str << std::endl;
	}
	return 0;
}