#include "BitcoinExchange.hpp"
#include <cmath>


BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
	_input.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
	*this = src;
}

BitcoinExchange::BitcoinExchange(std::string inputfile)
{
	std::fstream data("data.csv");
	_input.open(inputfile, std::ios::in | std::ios::out | std::ios::app);

	if (!data.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		exit(1);
	}
	std::string line;
	std::getline(data, line);
	while (std::getline(data, line))
	{
		std::string date = line.substr(0, line.find(','));
		std::string price = line.substr(line.find(',') + 1);
		_btcMap[date] = std::stod(price);
	}
	data.close();
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	(void)src;
	return (*this);
}

void BitcoinExchange::run()
{
	std::string line;

	std::getline(_input, line);
	while (std::getline(_input, line))
	{
		btcPair pair = sanitize(line);
		std::string date = pair.first;
		double price = pair.second;
		std::map<std::string, double>::iterator it = _btcMap.find(date);
		if (it != _btcMap.end())
		{
			double diff = std::abs(it->second - price);
			std::cout << date << ": " << diff << std::endl;
		}
		else
			std::cout << date << ": " << "No data" << std::endl;
	}
}

btcPair BitcoinExchange::sanitize(const std::string &line)
{
	btcPair pair;
	std::string date = trim(line.substr(0, line.find('|')));
	std::string price = trim(line.substr(line.find('|') + 1));

	validate(date, price);
	pair.first = date;
	pair.second = std::stod(price);
	return (pair);
}

std::string& BitcoinExchange::trim(const std::string &str)
{
	size_t first = str.find_first_not_of(' \n\t\r');
	size_t last = str.find_last_not_of(' \n\t\r');

	std::string res = std::string::npos == first ? "" : str.substr(first, (last - first + 1));
	return (res);
}

void BitcoinExchange::validate(const std::string &date, const std::string &price)
{
	if (date.empty() || price.empty())
		throw "Error: invalid input";

	if (date.size() != 10)
		throw "Error: invalid date";
	
	for(size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				throw "Error: invalid date";
		}
		else if (!std::isdigit(date[i]))
			throw "Error: invalid date";
	}

	if (!checkDate(date))
		throw "Error: invalid date";

	if (price[0] == '.')
		throw "Error: invalid price";
	
	for(size_t i = 0; i < price.size(); i++)
	{
		if (price[i] == '.')
			continue;
		if (!std::isdigit(price[i]))
			throw "Error: invalid price";
	}
}

bool BitcoinExchange::checkDate(const std::string &date)
{
	int year = std::stoi(date.substr(0, 4));
	int month = std::stoi(date.substr(5, 2));
	int day = std::stoi(date.substr(8, 2));

	if (year < 2009 || year > 2022)
		return (false);
	if (month < 01 || month > 12)
		return (false);
	if (day < 01 || day > 31)
		return (false);
	return (true);
}
