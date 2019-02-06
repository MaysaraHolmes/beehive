#ifndef ADC_HPP
#define ADC_HPP

#include "I2C.hpp"

#include <stdio.h>
#include <iostream>
#include <bitset>
#include <cstring>  // strlen()


class ADC{

	public:
		int bytesToRead = 4;
    int bytesToWrite = 2;

    I2C* bus;
		std::bitset<16> bitsetI2C;

    ADC(char* portI2C, int addrI2C);
    void readI2C(unsigned char* global_buffer);
    int writeI2C();
    //int getStatus();
    //double getTemp();
    //double getHum();

    ~ADC();

};

#endif // ADC_HPP
