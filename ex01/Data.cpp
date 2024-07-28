#include "Data.hpp"

Data::Data(int value) : _value(value) {}

Data::~Data() {}

int Data::getValue() const {
	return _value;
}

void Data::setValue(int value) {
	_value = value;
}

Data::Data() : _value(0) {}

Data::Data(const Data &other) {
	*this = other;
}

Data &Data::operator=(const Data &copy) {
	if (this != &copy) {
		_value = copy._value;
	}
	return *this;
}