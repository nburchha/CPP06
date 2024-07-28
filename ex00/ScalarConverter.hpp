#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iomanip>

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

	void conversionChar(char value) const;
	void conversionInt(int value) const;
	void conversionFloat(float value) const;
	void conversionDouble(double value) const;
};
