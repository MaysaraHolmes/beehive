#ifndef TEMPERATUREANDHUMIDITY_HPP
#define TEMPERATUREANDHUMIDITY_HPP

#include "I2C.hpp"

#include <stdio.h>
#include <iostream>
#include <bitset>
#include <cstring>  // strlen()
#include <string>


class TemperatureAndHumidity{

	public:
		int bytesToRead = 4;
    int bytesToWrite = 2;

    I2C* bus;

		//data buffer
		//unsigned char buffer[4] = {0};
		//unsigned char* buffer;
		std::bitset<32> bitsetI2C;
		unsigned int i;

    TemperatureAndHumidity(char* portI2C, int addrI2C);
    void readI2C(unsigned char* global_buffer);
    int writeI2C();
    int getStatus();
    double getTemp();
    double getHum();

    ~TemperatureAndHumidity();

};

#endif // TEMPERATUREANDHUMIDITY_HPP
