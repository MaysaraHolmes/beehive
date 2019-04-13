//! An abstract class
/*!
	 Used as a base class for sensors connected to the I2C bus of the RaspberryPi
*/

#ifndef SENSOR_HPP
#define SENSOR_HPP

#include "I2C.hpp"
#include <cmath>
#include <cstring>  // strlen()
#include <cstdint>

class Sensor{

	protected:
		//! A private variable.
		/*!
			Holding the sensor default bytes to read form the I2C bus
		*/
		int bytesToRead;
		//! A private variable.
		/*!
			Holding the sensor default bytes to write form the I2C bus
		*/
		int bytesToWrite;
		//! A private variable.
		/*!
			Holding the sensor I2C bus object created in the constructor
		*/
		I2C* bus;

	public:

		//! A constructor.
		/*!
			Create a new I2C object used to communicate with the sensor.
			\param bytesToRead default bytes to read form the I2C bus
			\param bytesToWrite default bytes to write form the I2C bus
			\param portI2C a char pointer holding which I2C bus on the Raspberry the peripheral is connected to.
			\param addrI2C an integer holding the address to the peripheral.
			\sa	I2C(char* portI2C, int slaveAddr)
		*/
    Sensor(int bytesToRead, int bytesToWrite, char* portI2C, int addrI2C) {
			this->bytesToRead = bytesToRead;
			this->bytesToWrite=bytesToWrite;
			this->bus = new I2C(portI2C, addrI2C);
		}

		//! A pure virtual member
		/*!
			Read data from the peripheral .
			\param global_buffer an unsigned char pointer where the data read is saved.
		*/
    virtual void readI2C(unsigned char* global_buffer)  = 0;

		//! A virtual member
		/*!
			Write data to the peripheral .
		*/
		virtual int writeI2C() {
			return bus->writeI2C(this->bytesToWrite);
		}

		//! A destructor.
		/*!
			Deallocates memory from heap
		*/
    ~Sensor(){
			delete bus;
		}
};

#endif // SENSOR_HPP
