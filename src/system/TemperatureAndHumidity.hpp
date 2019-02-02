#ifndef TEMPERATUREANDHUMIDITY_HPP
#define TEMPERATUREANDHUMIDITY_HPP

#include "I2C.hpp"

#include <stdio.h>
#include <iostream>
#include <bitset>


class TemperatureAndHumidity{

	public:
		int bytesToRead = 4;
    int bytesToWrite = 2;

    I2C* bus;

		//data buffer
		unsigned char buffer[4] = {0};


    TemperatureAndHumidity(char* portI2C, int addrI2C);
    void readI2C();
    int writeI2C();
    int getStatus(std::bitset<8> first8Bits);
    double getTemp();
    double getHum();

    ~TemperatureAndHumidity();

};

#endif // TEMPERATUREANDHUMIDITY_HPP
