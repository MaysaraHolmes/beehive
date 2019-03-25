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
    static Fan *saved_Fan_pointer[1];

public:
    Fan(int gpio = 18, int interruptPin=17);

    void setPwm(int pwm_value);
    void start();
    void stop();
    static void helper_func0();
    void onInterrupt();
    ~Fan();
};

#endif // FAN_HPP
