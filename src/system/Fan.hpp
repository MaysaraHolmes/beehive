#ifndef FAN_HPP
#define FAN_HPP

#include <stdio.h>
#include <iostream>
//#include <wiringPi.h>


class Fan {

private:
    int gpio;

public:
    Fan(int gpio = 18);

    void setPwm(int pwm_value);
    void stop();
    ~Fan();
};

#endif // FAN_HPP
