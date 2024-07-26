#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <cctype>

class ScalarConverter {
public:
	static void convert(const std::string& literal);

private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);

	bool isChar(const std::string& literal) const;
	bool isInt(const std::string& literal) const;
	bool isFloat(const std::string& literal) const;
	bool isDouble(const std::string& literal) const;

	void convertToChar(double value) const;
	void convertToInt(double value) const;
	void convertToFloat(double value) const;
	void convertToDouble(double value) const;
};
