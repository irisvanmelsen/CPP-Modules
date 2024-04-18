#ifndef DATA_HPP
# define DATA_HPP

#include <string>
#include <iostream>

class Data {
	private:
		int _value;
	public:
		Data();
		Data(int _value);

		int getValue() const;
		void setValue(int _value);
};

#endif