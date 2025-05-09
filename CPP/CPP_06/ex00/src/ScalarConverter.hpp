#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <limits>
# include <cctype>
# include <cstdlib>
# include <cmath>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter&	operator=(const ScalarConverter&);
		~ScalarConverter();

		static bool	handleSpecialCases(const std::string& literal);
		static void	printChar(double value);
		static void	printInt(double value);
		static void	printFloat(double value);
		static void	printDouble(double value);

	public:
		static void	convert(std::string& literal);
};

#endif
