#ifndef _BITCOINEXCHANGE_HPP_
# define _BITCOINEXCHANGE_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>

typedef std::pair<std::string, double> btcPair;
typedef std::map<std::string, double>  btcMap;

class BitcoinExchange
{
	private:
	 	btcMap _btcMap;
		std::fstream _input;

		btcPair sanitize(const std::string &line);
		std::string &trim(const std::string &str);
		void validate(const std::string &date, const std::string &price);
		bool checkDate(const std::string &date);
	public:
		BitcoinExchange();
		BitcoinExchange(std::string inputfile);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);

		void run();
};

#endif


