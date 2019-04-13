#ifndef SENSOR_HPP
#define SENSOR_HPP

#include "I2C.hpp"

#include <stdio.h>
#include <iostream>



class Sensor{

	protected:
		int bytesToRead;
		int bytesToWrite;

		I2C* bus;

	public:

    Sensor(int bytesToRead, int bytesToWrite, char* portI2C, int addrI2C) {
			this->bytesToRead = bytesToRead;
			this->bytesToWrite=bytesToWrite;
			this->bus = new I2C(portI2C, addrI2C);
		}

    virtual void readI2C(unsigned char* global_buffer)  = 0;

		virtual int writeI2C() {
			return bus->writeI2C(this->bytesToWrite);
		}

    ~Sensor(){
			delete bus;
		}

};

#endif // SENSOR_HPP
