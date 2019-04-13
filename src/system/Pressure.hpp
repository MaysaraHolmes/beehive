//! A  class for the MPL115A2 Barometer sensor
/*!
	 Handling communication with the sensor,
	 and converting the sensor measurements to human readable values
*/

#ifndef PRESSURE_HPP
#define PRESSURE_HPP

#include "Sensor.hpp"
#include <stdio.h>
#include <string>
#include <cmath>



class Pressure: public Sensor{

private:
    //! A private variable.
    /*!
      variable to hold the floating point coefficient a0
      needed to convert the read sensor bit to a human readable value
    */
    float a0;
    //! A private variable.
    /*!
      variable to hold the floating point coefficient b1
      needed to convert the read sensor bit to a human readable value
    */
    float b1;
    //! A private variable.
    /*!
      variable to hold the floating point coefficient b2
      needed to convert the read sensor bit to a human readable value
    */
    float b2;
    //! A private variable.
    /*!
      variable to hold the floating point coefficient c2
      needed to convert the read sensor bit to a human readable value
    */
    float c12;
    //! A private variable.
    /*!
      Holding the newest pressure-bit reading from the sensor
    */
    int pressure;
    //! A private variable.
    /*!
      Holding the newest temperature-bit reading from the sensor
    */
    int temp;
    //! A private variable.
    /*!
      Intermediate variable needed to convert the sensor data to a human readable value.
      Calculated by combining all the private variables
    */
    float pressureComp;


public:
    //! A constructor.
    /*!
      Call the Sensor constructor and readCoefficients(unsigned char* global_buffer)
      \param portI2C a char pointer holding the which I2C bus on the Raspberry the peripheral is connected to.
      \param addrI2C an integer holding the address to the peripheral.
      \sa Sensor(int bytesToRead, int bytesToWrite, char* portI2C, int addrI2C)
    */
    Pressure(char* portI2C, int addrI2C, unsigned char* global_buffer);
    //! Call the I2C-object write and read function to get sensor coefficients
    /*!
      Write (uint8_t)(0x04) to the sensor, followed by a read to get the
      coefficients we need to decrypt the values from the pressure sensor.
      Saves the coefficients in the corresponding private variables.
      \param global_buffer an unsigned char pointer where the data read is saved.
    */
    void readCoefficients(unsigned char* global_buffer);
    //! Call the I2C-object read function
    /*!
      Get the data read form the sensor and split the data into pressure,
      temperature and calculate the pressure component bits and saves them to the corresponding private variable.
      \param global_buffer an unsigned char pointer where the data read is saved.
    */
    void readI2C(unsigned char* global_buffer);
    //! Call the I2C-object write function
    int writeI2C();

    //! Convert the humidity bits into kPa
    /*!
      \return The humidity in kPa.
    */
    float getPressure();
    //! Convert the temperature bits into degrees
		/*!
			\return The temperature in degrees.
		*/
    float getTemp();
    //! A destructor.
    /*!
      Empty, can be used if more functions are integrated
    */
    ~Pressure();
};

#endif // PRESSURE_HPP
