#ifndef PRESSURE_HPP
#define PRESSURE_HPP

#include "Sensor.hpp"
#include <stdio.h>
#include <iostream>
#include <cstring>  // strlen()
#include <string>
#include <cmath> //remove?



class Pressure: public Sensor{

private:

    // variables to hold the floating point coefficients
    float a0;
    float b1;
    float b2;
    float c12;
    int pressure;
    int temp;
    float pressureComp;


public:
    Pressure(char* portI2C, int addrI2C, unsigned char* global_buffer);
    void readCoefficients(unsigned char* global_buffer);
    void readI2C(unsigned char* global_buffer);
    int writeI2C();

		//NOTE make const
    //returns kPa
    float getPressure();
    float getTemp();

    ~Pressure();
};

#endif // PRESSURE_HPP
