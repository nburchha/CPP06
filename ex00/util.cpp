#include "sstream"

std::string toString(int value)
{
	std::ostringstream os;
	os << value;
	return os.str();
}

std::string toString(float value)
{
	std::ostringstream os;
	os << value;
	return os.str();
}

std::string toString(double value)
{
	std::ostringstream os;
	os << value;
	return os.str();
}