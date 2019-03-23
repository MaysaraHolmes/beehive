#ifndef FAN_HPP
#define FAN_HPP

#include <stdio.h>
#include <iostream> //NOTE remove
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <wiringPi.h>


class Fan {

private:
    int gpio;
    int interruptPin;

public:
    Fan(int gpio = 18, int interruptPin=17);

    void setPwm(int pwm_value);
    void start();
    void stop();
    void onInterrupt();
    ~Fan();
};

#endif // FAN_HPP
