#include "json_dict.h"
#include "data/Integer.h"
#include "data/String.h"

std::vector<std::pair<json_object *, json_object *> > thisV;

json_dict::json_dict()
{
}

void json_dict::put(json_object *key, json_object *val)
{
	// std::cout << "put call" << std::endl;
	int index = find(key);
	if (!index)
	{
		v[index] = std::make_pair(key, val);
	}
	else
	{
		v.push_back(std::make_pair(key, val));
	}
}

int json_dict::find(json_object *key)
{
	int index = 0;

	if (key->type() == INT)
	{
		Integer *findkey = dynamic_cast<Integer *>(key);
		for (std::vector<std::pair<json_object *, json_object *> >::const_iterator it = v.begin(); it != v.end(); it++, index++)
		{
			if (it->first->type() == INT)
			{
				Integer *thiskey = dynamic_cast<Integer *>(it->first);
				if (findkey->val() == thiskey->val())
					return index;
			}
		}
	}
	else if (key->type() == STRING)
	{
		String *findkey = dynamic_cast<String *>(key);
		for (std::vector<std::pair<json_object *, json_object *> >::const_iterator it = v.begin(); it != v.end(); it++, index++)
		{
			if (it->first->type() == STRING)
			{
				String *thiskey = dynamic_cast<String *>(it->first);
				if (findkey->val().compare(thiskey->val()) == 0)
					return index;
			}
		}
	}

	return -1;
}

json_object *json_dict::parse(const char *ch, int length)
{
	json_dict *tmp = new json_dict();
	_index++; // '{' pass

	while (_index < length)
	{
		char thisch = ch[_index];
		json_object *key = json_object::parse(ch, length);
		_index++; // ':' pass
		json_object *value = json_object::parse(ch, length);
		tmp->put(key, value);
		if(ch[_index] == '}') break;
		_index++; // ',' pass
	}
	_index++; // '}' pass
	return tmp;
}

json_object *json_dict::operator[](json_object *key) const
{
	int index = 0;

	if (key->type() == INT)
	{
		Integer *findkey = dynamic_cast<Integer *>(key);
		for (std::vector<std::pair<json_object *, json_object *> >::const_iterator it = v.begin(); it != v.end(); it++, index++)
		{
			if (it->first->type() == INT)
			{
				Integer *thiskey = dynamic_cast<Integer *>(it->first);
				if (findkey->val() == thiskey->val())
					return it->second;
			}
		}
	}
	else if (key->type() == STRING)
	{
		String *findkey = dynamic_cast<String *>(key);
		for (std::vector<std::pair<json_object *, json_object *> >::const_iterator it = v.begin(); it != v.end(); it++, index++)
		{
			if (it->first->type() == STRING)
			{
				String *thiskey = dynamic_cast<String *>(it->first);
				if (findkey->val().compare(thiskey->val()) == 0)
					return it->second;
			}
		}
	}

	return nullptr;
}

json_object *json_dict::operator[](const std::string &key) const
{
	for (std::vector<std::pair<json_object *, json_object *> >::const_iterator it = v.begin(); it != v.end(); it++)
	{
		if (it->first->to_string() == key)
			return it->second;
	}
	return nullptr;
}

json_object *json_dict::operator[](int key) const
{
	for (std::vector<std::pair<json_object *, json_object *> >::const_iterator it = v.begin(); it != v.end(); it++)
	{
		if (it->first->to_string() == std::to_string(key))
			return it->second;
	}
	return nullptr;
}

json_object::_type json_dict::type()
{
	return DICT;
}

std::string json_dict::to_string()
{
//	std::cout << "to_string call" << std::endl;
	std::string str = "{";
	for (std::vector<std::pair<json_object *, json_object *> >::const_iterator it = v.begin(); it != v.end(); it++)
	{
		str.append(it->first->to_string())
			.append(": ")
			.append(it->second->to_string());

		if (it != v.end() - 1)
		{
			str.append(", ");
		}
	}
	str.append("}");

	return str;
}
