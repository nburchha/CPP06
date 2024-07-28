#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

bool ScalarConverter::isChar(const std::string& literal) const
{
	return literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string& literal) const
{
	char* end;
	long value = std::strtol(literal.c_str(), &end, 10);
	return *end == '\0' && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max();
}

bool ScalarConverter::isFloat(const std::string& literal) const
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
		return true;
	}
	char* end;
	// float value = std::strtof(literal.c_str(), &end);
	std::strtof(literal.c_str(), &end);
	return *end == 'f' && *(end + 1) == '\0';
}

bool ScalarConverter::isDouble(const std::string& literal) const
{
	if (literal == "-inf" || literal == "+inf" || literal == "nan") {
		return true;
	}
	char* end;
	// double value = std::strtod(literal.c_str(), &end);
	std::strtod(literal.c_str(), &end);
	return *end == '\0';
}

void ScalarConverter::conversionChar(char value) const
{
	int	i = static_cast<int>(value);
	float	ft = static_cast<float>(value);
	double	db = static_cast<double>(value);

	std::cout << "char : '" << value << "'" << std::endl;
	std::cout << "int : " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float : " << ft << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double : " << db << std::endl;
}

void ScalarConverter::conversionInt(int value) const
{
	char c = static_cast<char>(value);
	float ft = static_cast<float>(value);
	double db = static_cast<double>(value);

	if (std::isprint(c))
		std::cout << "char : '" << c << "'" << std::endl;
	else
		std::cout << "char : Non displayable" << std::endl;
	std::cout << "int : " << value << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float : " << ft << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double : " << db << std::endl;
}

void ScalarConverter::conversionFloat(float value) const
{
	char c = static_cast<char>(value);
	int i = static_cast<int>(value);
	double db = static_cast<double>(value);
	std::string str = "+inf+inff-inf-inffnannanf";

	if (std::isprint(c))
		std::cout << "char : '" << c << "'" << std::endl;
	else
		std::cout << "char : Non displayable" << std::endl;
	if (str.find(std::to_string(value)) != std::string::npos || value > INT_MAX || value < INT_MIN)
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float : " << value << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double : " << db << std::endl;
}

void ScalarConverter::conversionDouble(double value) const
{
	char c = static_cast<char>(value);
	int i = static_cast<int>(value);
	float ft = static_cast<float>(value);
	std::string str = "+inf+inff-inf-inffnannanf";

	if (std::isprint(c))
		std::cout << "char : '" << c << "'" << std::endl;
	else
		std::cout << "char : Non displayable" << std::endl;
	if (str.find(std::to_string(value)) != std::string::npos || value > INT_MAX || value < INT_MIN)
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float : " << ft << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double : " << value << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
	ScalarConverter converter;
	if (converter.isChar(literal))
		converter.conversionChar(literal[0]);
	else if (converter.isInt(literal))
		converter.conversionInt(std::atoi(literal.c_str()));
	else if (converter.isFloat(literal))
		converter.conversionFloat(std::strtof(literal.c_str(), nullptr));
	else if (converter.isDouble(literal))
		converter.conversionDouble(std::strtod(literal.c_str(), nullptr));
	else
	{
		std::cout << "Error: No valid type found" << std::endl;
		return;
	}
}
