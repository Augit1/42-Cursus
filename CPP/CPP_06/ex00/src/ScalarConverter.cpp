#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

bool	ScalarConverter::handleSpecialCases(const std::string& literal)
{
    if (literal == "nan" || literal == "nanf"
		|| literal == "+inf" || literal == "-inf"
		|| literal == "+inff" || literal == "-inff")
	{
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		{
            std::cout << "float: " << literal << std::endl;
            std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
        }
		else
		{
            std::cout << "float: " << literal << "f" << std::endl;
            std::cout << "double: " << literal << std::endl;
        }
        return true;
    }
    return false;
}

void	ScalarConverter::printChar(double value)
{
    if (value < std::numeric_limits<char>::min()
			|| value > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void	ScalarConverter::printInt(double value)
{
    if (value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void	ScalarConverter::printFloat(double value)
{
	float	f = static_cast<float>(value);
	if (std::isnan(f) || std::isinf(f))
	{
		std::cout <<"float: " << f << "f" << std::endl;
		return ;
	}
	std::cout << "float: " << f;
	if (f == floorf(f) && !std::isinf(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void	ScalarConverter::printDouble(double value)
{
	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "double: " << value << std::endl;
		return ;
	}
	std::cout << "double: " << value;
	if (value == floor(value) && !std::isinf(value))
		std::cout << ".0";
	std::cout << std::endl;
}

void	ScalarConverter::convert(std::string& literal)
{
	if (literal.empty())
	{
		std::cerr << "Error: Empty string" << std::endl;
		return ;
	}
	
	if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		char	value = literal[0];
		std::cout << "char: '" << value << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(value) << std::endl;
		std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
		return ;
	}

	if (handleSpecialCases(literal))
		return ;

	char	*endPtr;
	double	doubleValue = strtod(literal.c_str(), &endPtr);
	if (endPtr == literal.c_str())
	{
        std::cerr << "Error: Invalid literal" << std::endl;
        return;
    }
	if (*endPtr != '\0')
	{
		if (!((*endPtr == 'f' || *endPtr == 'F') && (endPtr + 1 == literal.c_str() + literal.length())))
		{
			std::cerr << "Error: Invalid literal" << std::endl;
			return ;
		}
	}
    printChar(doubleValue);
    printInt(doubleValue);
    printFloat(doubleValue);
    printDouble(doubleValue);
}
