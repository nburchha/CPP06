#pragma once

class Data
{
	public:
		int getValue() const;
		void setValue(int value);
		Data(int value);
		~Data();
	private:
		int _value;
		Data();
		Data(const Data &other);
		Data &operator=(const Data &copy);
};

