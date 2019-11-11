#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

class vehicle
{
protected:
    bool has_name;
    int wheel_number;
    int max_speed;

public:
    vehicle();
    explicit vehicle(int wheel_number, int max_speed);
    explicit vehicle(int wheel_number, int max_speed, bool has_name);
    int get_wheel_number();
    int get_max_speed();
    bool get_has_name();
    virtual const char *get_class_name();
    void set_wheel_number(int wheel_number);
    void set_max_speed(int max_speed);
    void set_has_name(bool has_name);
};

#endif