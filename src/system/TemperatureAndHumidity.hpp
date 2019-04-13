//! A  class for the HIH6131 Temperatur & Humidity sensor
/*!
	 Handling how to communicate with the sensor,
	 and converting the sensor measurements to human readable values
*/

#ifndef TEMPERATUREANDHUMIDITY_HPP
#define TEMPERATUREANDHUMIDITY_HPP

#include "Sensor.hpp"
#include <stdio.h>
#include <cstring>  // strlen()
#include <string>
#include <cmath>


class TemperatureAndHumidity: public Sensor{

	private:
		//! A private variable.
		/*!
			Holding the newest status-bit reading from the sensor
		*/
		uint8_t status;
		//! A private variable.
		/*!
			Holding the newest humidity-bit reading from the sensor
		*/
		uint16_t humidity;
		//! A private variable.
		/*!
			Holding the newest temperature-bit reading from the sensor
		*/
		uint16_t temperature;

	public:
		//! A constructor.
		/*!
			Call the Sensor constructor
			\param portI2C a char pointer holding the which I2C bus on the Raspberry the peripheral is connected to.
			\param addrI2C an integer holding the address to the peripheral.
			\sa Sensor(int bytesToRead, int bytesToWrite, char* portI2C, int addrI2C)
		*/
    TemperatureAndHumidity(char* portI2C, int addrI2C);
		//! Call the I2C-object read function
		/*!
			Get the data read form the sensor and split the data into status,
			humidity and temperatur bits and saves them to the corresponding private variable.
			\param global_buffer an unsigned char pointer where the data read is saved.
		*/
    void readI2C(unsigned char* global_buffer);
		//! Call the I2C-object write function
		int writeI2C();
		//! Convert the status bits into a integer from 0-3
		/*!
			\return The status of the sensor.
		*/
    unsigned int getStatus();
		//! Convert the temperature bits into degrees
		/*!
			\return The temperature in degrees.
		*/
    double getTemp();
		//! Convert the humidity bits into %RH
		/*!
			\return The humidity in %RH.
		*/
    double getHum();

		//! A destructor.
    /*!
      Empty, can be used if more functions are integrated
    */
    ~TemperatureAndHumidity();
};

#endif // TEMPERATUREANDHUMIDITY_HPP
