#ifndef TEMPERATUREANDHUMIDITY_HPP
#define TEMPERATUREANDHUMIDITY_HPP

//#include "I2C.hpp" //remove?
#include "Sensor.hpp"

#include <stdio.h>
#include <iostream>
#include <bitset>
#include <cstring>  // strlen()
#include <string>
#include <cmath>


class TemperatureAndHumidity: public Sensor{

private:
		//remove the constants here, only set them in constructor
		//int bytesToRead = 4;
    //int bytesToWrite = 2;

    //I2C* bus;

		uint8_t status;
		uint16_t humidity;
		uint16_t temperature;

public:
    TemperatureAndHumidity(char* portI2C, int addrI2C);
    void readI2C(unsigned char* global_buffer);
    int writeI2C();
		//NOTE make const
    unsigned int getStatus();
    double getTemp();
    double getHum();

    ~TemperatureAndHumidity();
};

#endif // TEMPERATUREANDHUMIDITY_HPP
