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

void ScalarConverter::convertToChar(double value) const
{
	if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max() || std::isnan(value))
		std::cout << "char: impossible" << std::endl;
	else
	{
		char c = static_cast<char>(value);
		if (std::isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
}

void ScalarConverter::convertToInt(double value) const
{
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || std::isnan(value))
		std::cout << "int: impossible" << std::endl;
	else
	{
		int i = static_cast<int>(value);
		std::cout << "int: " << i << std::endl;
	}
}

void ScalarConverter::convertToFloat(double value) const
{
	if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max() || std::isnan(value))
		std::cout << "float: impossible" << std::endl;
	else
	{
		float f = static_cast<float>(value);
		std::cout << "float: " << f << "f" << std::endl;
	}
}

void ScalarConverter::convertToDouble(double value) const
{
	if (value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max() || std::isnan(value))
		std::cout << "double: impossible" << std::endl;
	else {
		std::cout << "double: " << value << std::endl;
	}
}

void ScalarConverter::convert(const std::string& literal)
{
	ScalarConverter converter;
	double value;
	if (converter.isChar(literal))
		value = literal[0];
	else if (converter.isInt(literal))
		value = std::strtol(literal.c_str(), nullptr, 10);
	else if (converter.isFloat(literal))
		value = std::strtof(literal.c_str(), nullptr);
	else if (converter.isDouble(literal))
		value = std::strtod(literal.c_str(), nullptr);
	else
	{
		std::cout << "Error: No valid type found" << std::endl;
		return;
	}

	converter.convertToChar(value);
	converter.convertToInt(value);
	converter.convertToFloat(value);
	converter.convertToDouble(value);
}
