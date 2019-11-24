#include "json_list.h"

json_list::json_list()
{
}

json_object *json_list::parse(const char *ch, int length)
{
    // std::cout << "list parse call" << std::endl;
    json_list *tmp = new json_list();
    _index++; // '[' pass
    while (_index < length && ch[_index] != ']')
    {
        json_object *val = json_object::parse(ch, length);
        tmp->v.push_back(val);
        if (ch[_index] == ']')
        {
            break;
        }
        _index++; // ',' pass
    }
    _index++;
    return tmp;
}

json_object *json_list::operator[](int key) const
{
    return v[key];
}

json_object::_type json_list::type()
{
    return LIST;
}

std::string json_list::to_string()
{
    //	std::cout << "to_string call" << std::endl;
    std::string str = "[";
    for (std::vector<json_object *>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        str.append((*it)->to_string());

        if (it != v.end() - 1)
        {
            str.append(", ");
        }
    }
    str.append("]");

    return str;
}