#include <iostream>
#include <string>
#include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char **)
// {
// 	Array<int> numbers(MAX_VAL);
// 	int *mirror = new int[MAX_VAL];
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 	}
// 	// SCOPE
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		if (mirror[i] != numbers[i])
// 		{
// 			std::cerr << "didn't save the same value!!" << std::endl;
// 			return 1;
// 		}
// 	}
// 	try
// 	{
// 		numbers[-2] = 0;
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		numbers[MAX_VAL] = 0;
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		numbers[i] = rand();
// 	}
// 	delete[] mirror; //
// 	return 0;
// }

int main()
{
	try
	{
		Array<int> arr(5);
		Array<int> arr2(5);
		Array<std::string> strarr(0);
		Array<std::string> strarr2(2);

		strarr2[0] = "Hello";
		strarr2[1] = "World";

		std::cout << "strarr2: " << std::endl;
		for (int i = 0; i < 2; i++)
			std::cout << "content: " + strarr2[i] << " | " << "size: " << strarr2[i].size() << std::endl;
		std::cout << std::endl;

		for (int i = 0; i < 5; i++)
		{
			arr[i] = i;
			arr2[i] = i + 5;
		}

		std::cout << "arr: ";
		for (int i = 0; i < 5; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;

		std::cout << "arr2: ";
		for (int i = 0; i < 5; i++)
			std::cout << arr2[i] << " ";
		std::cout << std::endl;

		std::cout << strarr[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
		return 0;
}
