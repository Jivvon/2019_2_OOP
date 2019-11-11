#include "vehicle.h"

vehicle::vehicle()
{
    has_name = false;
    wheel_number = -1;
    max_speed = -1;
}
vehicle::vehicle(int wheel_number, int max_speed)
{
    has_name = true;
    this->wheel_number = wheel_number;
    this->max_speed = max_speed;
}
vehicle::vehicle(int wheel_number, int max_speed, bool has_name)
{
    this->has_name = has_name;
    this->wheel_number = wheel_number;
    this->max_speed = max_speed;
}
int vehicle::get_wheel_number()
{
    return this->wheel_number;
}
int vehicle::get_max_speed()
{
    return this->max_speed;
}
bool vehicle::get_has_name()
{
    return this->has_name;
}
const char *vehicle::get_class_name()
{
    char *tmp = "vehicle";
    return tmp;
}
void vehicle::set_wheel_number(int wheel_number)
{
    this->wheel_number = wheel_number;
}
void vehicle::set_max_speed(int max_speed)
{
    this->max_speed = max_speed;
}
void vehicle::set_has_name(bool has_name)
{
    this->has_name = has_name;
}
