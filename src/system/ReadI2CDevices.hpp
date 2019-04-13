//! A  class to gather all the readings from the different sensors.
/*!
   Hold all the addresses for the different sensors we want to read/write to.
   Gather the human readable values from the sensors,
   for easy use outside the class.
*/

#ifndef READI2CDEVICES_HPP
#define READI2CDEVICES_HPP

#include "TemperatureAndHumidity.hpp"
#include "Pressure.hpp"
#include "Sensor.hpp"

#include <stdio.h>
#include <iostream>
#include <cstring>  // strlen()
#include <vector>
#include <string>

#define I2C_PORT1 (char*)"/dev/i2c-1"
#define I2C_PORT2 (char*)"/dev/i2c-3"

#define NB_DEVICES_PORT1 2
#define NB_DEVICES_PORT2 1
#define NB_DEVICES 3

#define PORT1_ADDR_TEMP_AND_HUM 0X27
#define PORT2_ADDR_PRESSURE 0X60
#define PORT2_ADDR_TEMP_AND_HUM 0X27



class ReadI2CDevices{

private:

  //! A private variable.
  /*!
    Global buffer where all the sensors saves the measurements.
  */
  unsigned char global_buffer[20]={0};
  //! A private variable.
  /*!
    Sensor object, pointing to the temperature and humidity sensor on I2C bus 1.
  */
  Sensor* th1;
  //! A private variable.
  /*!
    Sensor object, pointing to the temperature and humidity sensor on I2C bus 2.
  */
  Sensor* th2;
  //! A private variable.
  /*!
    Sensor object, pointing to the pressure sensor on I2C bus 1.
  */
  Sensor* pr;
  //std::vector<Sensor*> sensors;
  //Sensor* sensors[NB_DEVICES];

  //! Create all the sensor objects we want to communicate with
  /*!
    Called by the constructor.
    Saves the objects in the corresponding private variables.
    \sa ReadI2CDevices();
  */
  void createSensorObjects();

public:
    //! A constructor.
    /*!
      Call the function createSensorObjects();
      \sa createSensorObjects()
    */
    ReadI2CDevices();
    //! Write to all the peripherals.
    /*!
      Call the virtual function writeI2C() in Sensor.hpp for all the sensors
      \sa writeI2C()
    */
    void writeAll();
    //! Read data from all the peripherals.
    /*!
      Call the pure virtual function readI2C(unsigned char* global_buffer) in Sensor.hpp for all the sensors.
      Sends the private global_buffer to save the readings.
      \return A string of all the human readable data read form the sensors
      \sa readI2C(unsigned char* global_buffer)  = 0;
    */
    std::string readAll();
    //! A destructor.
    /*!
      Deallocates memory from heap
    */
    ~ReadI2CDevices();
};

#endif // READI2CDEVICES_HPP
