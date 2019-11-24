#include "String.h"

String::String(const std::string &str)
{
	_val = str;
}

std::string String::val()
{
	return _val;
}

void String::set_val(const std::string &str)
{
	_val = str;
}

json_object *String::parse(const char *ch, int length, char base)
{
	_index++;
	int start = _index;
	while (base != ch[_index])
	{
		_index++;
	}
	int end = _index;
	_index++;

	std::string str = std::string(ch).substr(start, end - start);
	return new String(str);
}

String::_type String::type()
{
	return STRING;
}

std::string String::to_string()
{
	return "'" + _val + "'";
}
