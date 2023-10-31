#ifndef _BITCOINEXCHANGE_HPP_
# define _BITCOINEXCHANGE_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>
#include <cmath>
#include <sstream>

typedef std::pair<std::string, double> btcPair;
typedef std::map<std::string, double>  btcMap;

class BitcoinExchange
{
	private:
	 	btcMap _btcMap;
		std::fstream _input;
		std::string _line;

		btcPair sanitize(const std::string &line);
		std::string trim(const std::string &str);
		void validate(const std::string &date, const std::string &price);
		bool checkDate(const std::string &date);
		double stod(const std::string &str);
	public:
		BitcoinExchange();
		BitcoinExchange(std::string inputfile);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);

		void run();
};

#endif


