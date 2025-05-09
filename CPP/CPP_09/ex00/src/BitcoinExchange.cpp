#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _bitcoinRates(other._bitcoinRates) {}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_bitcoinRates = other._bitcoinRates;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::loadMap(const std::string& newFile)
{
	std::ifstream file(newFile.c_str());
	if (!file.is_open())
		throw std::runtime_error("could not open file.");
	std::string	line;
	while (std::getline(file, line))
	{
		std::istringstream	ss(line);
		std::string	date;
		float	rate;
		if (std::getline(ss, date, ',') && ss >> rate)
			_bitcoinRates[date] = rate;
	}
}

float	BitcoinExchange::getRate(const std::string& date)	const
{
	if (_bitcoinRates.empty())
		throw std::runtime_error("No data available.");
	std::map<std::string, float>::const_iterator it = _bitcoinRates.lower_bound(date);
	if (it == _bitcoinRates.end() || it->first > date)
	{
		if (it == _bitcoinRates.begin())
			throw std::runtime_error("No valid date before the given date.");
		--it;
	}
	return it->second;
}
