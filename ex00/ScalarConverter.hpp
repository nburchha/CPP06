#pragma once

#include <iostream>

// Type codes
#define CHAR_TYPE 1
#define INT_TYPE 2
#define FLOAT_TYPE 3
#define DOUBLE_TYPE 4
#define PSEUDO_LITERAL_TYPE 5
#define INVALID_TYPE -1 

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

		static int checkType(const std::string str);

		static void displayChar(const std::string str);
		static void displayInt(const std::string str);
		static void displayFloat(const std::string str);
		static void displayDouble(const std::string str);
	public:
		static void convert(const std::string &str);
};