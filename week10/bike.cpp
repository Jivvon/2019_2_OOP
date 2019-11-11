#include "bike.h"

bike::bike()
{
    bike_name = "no_name";
    bike_number = -1;
}
bike::bike(int wheel_number, int max_speed)
{
    bike_name = "no_name";
    bike_number = -1;
    this->wheel_number = wheel_number;
    this->max_speed = max_speed;
}
bike::bike(int wheel_number, int max_speed, char *bike_name)
{
    this->wheel_number = wheel_number;
    this->max_speed = max_speed;
    this->bike_name = bike_name;
    bike_number = -1;
}
bike::bike(int wheel_number, int max_speed, char *bike_name, int bike_number)
{
    this->wheel_number = wheel_number;
    this->max_speed = max_speed;
    this->bike_name = bike_name;
    this->bike_number = bike_number;
    this->has_name = has_name;
}
bike::bike(int wheel_number, int max_speed, char *bike_name, int bike_number, bool has_name)
{
    this->wheel_number = wheel_number;
    this->max_speed = max_speed;
    this->bike_name = bike_name;
    this->bike_number = bike_number;
    this->has_name = has_name;
}
int bike::get_bike_number()
{
    return this->bike_number;
}
char *bike::get_bike_name()
{
    return this->bike_name;
}
const char *bike::get_class_name()
{
    char *tmp = "bike";
    return tmp;
}
void bike::set_bike_name(char *bike_name)
{
    this->bike_name = bike_name;
}
void bike::set_bike_number(int bike_number)
{
    this->bike_number = bike_number;
}