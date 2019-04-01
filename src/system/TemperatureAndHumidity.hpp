#ifndef TEMPERATUREANDHUMIDITY_HPP
#define TEMPERATUREANDHUMIDITY_HPP


#include "Sensor.hpp"
#include <stdio.h>
#include <iostream>
#include <cstring>  // strlen()
#include <string>
#include <cmath>


class TemperatureAndHumidity: public Sensor{

private:
		uint8_t status;
		uint16_t humidity;
		uint16_t temperature;

public:
    TemperatureAndHumidity(char* portI2C, int addrI2C);
    void readI2C(unsigned char* global_buffer);
    int writeI2C();
    unsigned int getStatus();
    double getTemp();
    double getHum();

    ~TemperatureAndHumidity();
};

#endif // TEMPERATUREANDHUMIDITY_HPP
