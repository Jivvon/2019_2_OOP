#ifndef CAR_H
#define CAR_H

#include "vehicle.h"

class car : public vehicle
{
private:
    char *car_name;

public:
    car();
    explicit car(int wheel_number, int max_speed);
    explicit car(int wheel_number, int max_speed, char *car_name);
    explicit car(int wheel_number, int max_speed, char *car_name, bool has_name);
    char *get_car_name();
    const char *get_class_name();
    void set_car_name(char *car_name);
};

#endif