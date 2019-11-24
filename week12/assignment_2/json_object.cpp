#include "json_object.h"
#include "json_dict.h"
#include "json_list.h"
#include "data/Integer.h"
#include "data/String.h"

int json_object::_index = 0;

json_object *json_object::parse(const char *ch, int length)
{
	while (_index < length)
	{
		const char thisch = ch[_index];
		if (thisch == '\0' || thisch == '}' || thisch == ']')
		{
			return nullptr;
		}
		else if (thisch == ',' || thisch == ' ')
		{
			_index++;
			continue;
		}
		else if (thisch == '[')
		{
			return json_list::parse(ch, length);
		}
		else if (thisch == '{')
		{
			return json_dict::parse(ch, length);
		}
		else if (thisch >= '0' && thisch <= '9')
		{
			return Integer::parse(ch, length);
		}
		else if (thisch == '\"' || thisch == '\'')
		{
			return String::parse(ch, length, thisch);
		}
		else
		{
			_index++;
		}
	}
}

json_object *json_object::parse(const std::string &str)
{
	json_object::_index = 0;
	const char *ch = str.c_str();
	return parse(ch, str.length());
}
