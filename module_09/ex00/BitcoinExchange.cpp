#include "BitcoinExchange.hpp"



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
	_input.open(inputfile.c_str(), std::ios::in | std::ios::out | std::ios::app);

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
		_btcMap[date] = stod(price);
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
	if (line != "date | value")
	{
		std::cerr << "Error: invalid input" << std::endl;
		exit(1);
	}
	while (std::getline(_input, line))
	{
		try
		{
			btcPair pair = sanitize(line);
			std::string date = pair.first;
			double rate = pair.second;
			btcMap::iterator it = _btcMap.lower_bound(date);


			if (!_btcMap.count(date))
				it--;
			if (it == _btcMap.end())
				throw "Error: no data";
			std::cout << date << " " << rate << " => " << rate * it->second << std::endl;
		}
		catch (const char *e)
		{
			std::cout << e << std::endl;
		}
		catch (...)
		{
			std::cout << "Error: invalid input => " << _line << std::endl;
		}
	}
}

btcPair BitcoinExchange::sanitize(const std::string &line)
{
	_line = line;
	btcPair pair;
	std::string date = trim(line.substr(0, line.find('|')));
	std::string price = trim(line.substr(line.find('|') + 1));

	validate(date, price);
	pair.first = date;
	pair.second = stod(price);
	return (pair);
}

std::string BitcoinExchange::trim(const std::string &str)
{
	size_t first = str.find_first_not_of(" \n\t\r");
	size_t last = str.find_last_not_of(" \n\t\r");

	std::string res = std::string::npos == first ? "" : str.substr(first, (last - first + 1));
	return (res);
}

void BitcoinExchange::validate(const std::string &date, const std::string &price)
{
	if (date.empty() || price.empty() || date == price)
		throw false;

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

	if (stod(price) > 1000)
		throw "Error: too large a number";

	if (stod(price) < 0)
		throw "Error: not a positive number";
}

bool BitcoinExchange::checkDate(const std::string &date)
{
	std::stringstream ss(date);
	int year, month, day;

	ss >> year;
	ss.ignore(1);
	ss >> month;
	ss.ignore(1);
	ss >> day;

	if (year < 2009)
		return (false);
	if (month < 01 || month > 12)
		return (false);
	if (day < 01 || day > 31)
		return (false);
	return (true);
}

double BitcoinExchange::stod(const std::string &str)
{
	std::stringstream ss(str);
	double res;
	return (ss >> res ? res : 0);
}

