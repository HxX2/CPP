#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void)src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return (*this);
}

void ScalarConverter::convert(std::string str)
{
	std::string pr;

	try
	{
		std::cout << "char: ";

		int num = std::stoi(str);
		char c = static_cast<char>(num);

		if (num < 32 || num > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << c << "'" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}

	try
	{
		std::cout << "int: ";

		int i = static_cast<int>(std::stoi(str));
		std::cout << i << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}

	try
	{
		std::cout << "float: ";

		float f = static_cast<float>(stof(str));

		pr = std::floor(f) == f ? ".0" : "";
		if (str == "nan" || str == "-inf" || str == "+inf" || str == "inf")
			std::cout << str << "f" << std::endl;
		else
			std::cout << f << pr << "f" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}

	try
	{
		std::cout << "double: ";

		double d = static_cast<double>(stod(str));

		pr = std::floor(d) == d ? ".0" : "";
		if (str == "nan" || str == "-inf" || str == "+inf" || str == "inf")
			std::cout << str << std::endl;
		else
			std::cout << d << pr << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
}
