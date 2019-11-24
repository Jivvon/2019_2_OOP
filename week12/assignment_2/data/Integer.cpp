#include "Integer.h"

Integer::Integer(int value)
{
	_val = value;
}

int Integer::val()
{
	return _val;
}

void Integer::set_val(const int &value)
{
	_val = value;
}

json_object *Integer::parse(const char *ch, int length)
{
	// _index++;
	int start = _index;
	while (ch[_index] >= '0' && ch[_index] <= '9')
	{
		_index++;
	}
	int end = _index;
	// _index++;

	std::string str = std::string(ch).substr(start, end - start);
	// std::cout << "test" << std::endl;
	str += '\0';
	return new Integer(atoi(str.c_str()));
}

Integer::_type Integer::type()
{
	return INT;
}

std::string Integer::to_string()
{
	return std::to_string(_val);
}
