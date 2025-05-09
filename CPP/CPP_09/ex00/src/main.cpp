#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <cmath>

bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool	isValidDate(const std::string& dateStr)
{
	std::istringstream	ss(dateStr);
	int	year, month, day;
	char	dash1, dash2;
	
	if (!(ss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-')
		return false;
	if (year < 2009 || year > 2025 || month < 1 || month > 12 || day < 1)
		return false;
	int	dayInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && isLeapYear(year))
		dayInMonth[1] = 29;
	return day <= dayInMonth[month - 1];
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./btc <file>" << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange	exchange;

		exchange.loadMap("data.csv");
		std::ifstream	inputFile(argv[1]);
		if (!inputFile.is_open())
			throw std::runtime_error("could not open file.");

		std::string	line;
		std::getline(inputFile, line);
		while (std::getline(inputFile, line))
		{
			std::istringstream	ss(line);
			std::string			date, valueStr;

			if (std::getline(ss, date, '|') && std::getline(ss, valueStr))
			{
				date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
				date.erase(0, date.find_first_not_of(" \t\n\r\f\v"));
				valueStr.erase(valueStr.find_last_not_of(" \t\n\r\f\v") + 1);
				valueStr.erase(0, valueStr.find_first_not_of(" \t\n\r\f\v"));

				if (!isValidDate(date))
					std::cerr << "Error: invalid date => " << date << std::endl;

				std::stringstream	ss(valueStr);
				float	num;
				if (!(ss >> num) || !(ss.eof()))
				{
					std::cerr << "Error: not a number => " << valueStr << std::endl;
					continue ;
				}
					
				float	value = atof(valueStr.c_str());

				if (value < 0 || value > 1000)
				{
					if (value < 0)
						std::cerr << "Error: not a positive number => " << value << std::endl;
					else if (value > 1000)
						std::cerr << "Error: too large a number => " << value << std::endl;
					continue ;
				}

				float	rate = exchange.getRate(date);

				std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
			}
			else
				std::cerr << "Error: bad input => " << line << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
