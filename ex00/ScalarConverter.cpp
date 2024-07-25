#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &str)
{
	int type = checkType(str);
	switch (type)
	{
		case 1:
			displayChar(str);
			break;
		case 2:
			displayInt(str);
			break;
		case 3:
			displayFloat(str);
			break;
		case 4:
			displayDouble(str);
			break;
		default:
			std::cout << "Error: No valid type found" << std::endl;
	}
}

int ScalarConverter::checkType(const std::string str)
{
	if (str.length() == 3 && str.front() == '\'' && str.back() == '\'' && std::isprint(str[1])) {
		return CHAR_TYPE;
	}

	bool isNegative = (str[0] == '-');
	bool hasDot = false;
	bool hasF = false;
	bool isPseudo = false;

	for (size_t i = (isNegative ? 1 : 0); i < str.length(); ++i) {
		if (!std::isdigit(str[i])) {
			if (str[i] == '.' && !hasDot) {
				hasDot = true;
			} else if ((str[i] == 'f' || str[i] == 'F') && i == str.length() - 1 && hasDot) {
				hasF = true;
			} else if (str == "nanf" || str == "-inff" || str == "+inff" || str == "nan" || str == "-inf" || str == "+inf") {
				isPseudo = true;
				break;
			} else {
				return INVALID_TYPE;
			}
		}
	}

	if (isPseudo) {
		return PSEUDO_LITERAL_TYPE;
	} else if (hasF) {
		return FLOAT_TYPE;
	} else if (hasDot) {
		return DOUBLE_TYPE;
	} else {
		return INT_TYPE;
	}
}