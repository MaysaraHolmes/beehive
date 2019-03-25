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
    //static Fan *saved_Fan_pointer;
static int x;

public:
    Fan(int gpio = 18, int interruptPin=7);
//	void setFanPointer();

	void setPwm(int pwm_value);
    void start();
    void stop();

    static void helper_func0()
    {
    	std::cout << "in helper_func for pin 0: "<<std::endl;
     // saved_Fan_pointer->onInterrupt();
    }/*
    static void helper_func1()
    {
      std::cout << "in helper_func for pin 1: ";
      saved_Fan_pointer->onInterrupt();
    }
    static constexpr void (*helper_function[2])() = {
      helper_func0,
      helper_func1
    };*/
    void Fan::readAlarmPin();
    void onInterrupt();
    ~Fan();
};

#endif // FAN_HPP
