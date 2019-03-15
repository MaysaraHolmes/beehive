#ifndef PRESSURE_HPP
#define PRESSURE_HPP

//#include "I2C.hpp" //remove?
#include "Sensor.hpp"

#include <stdio.h>
#include <iostream>
#include <bitset>
#include <cstring>  // strlen()
#include <string>
#include <cmath> //remove?



class Pressure: public Sensor{

private:
		//remove the constants here, only set them in constructor
		//int bytesToRead = 4;
    //int bytesToWrite = 2;

    //reads 10bits???
    uint16_t pressureBits;
    uint16_t tempBits;
    float pressureComp;


public:
    Pressure(char* portI2C, int addrI2C);
    void readI2C(unsigned char* global_buffer);
    int writeI2C();

		//NOTE make const
    //returns kPa
    float getPressure();
    float getTemp();

    ~Pressure();
};

#endif // PRESSURE_HPP
