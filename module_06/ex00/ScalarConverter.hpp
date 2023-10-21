#ifndef _SCALARCONVERTER_HPP_
#define _SCALARCONVERTER_HPP_

#include <iostream>
#include <string>
#include <cmath>

class ScalarConverter
{
private:
	ScalarConverter();
public:
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	ScalarConverter &operator=(const ScalarConverter &src);

	static void convert(std::string str);
};

#endif