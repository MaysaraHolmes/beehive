#ifndef READI2CDEVICES_HPP
#define READI2CDEVICES_HPP

#include "I2C.hpp" //remove?
#include "TemperatureAndHumidity.hpp"// remove, include sensors instead
#include "Pressure.hpp" //remove? just include sensor?
#include "Sensor.hpp"

#include <stdio.h>
#include <iostream>
#include <bitset>
#include <cstring>  // strlen()
#include <vector>
#include <string>
#include "Fan.hpp"

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
  //I2C* bus1;
  //I2C* bus2;
  //int deviceAddrsPort1[NB_DEVICES_PORT1] = {PORT1_ADDR_TEMP_AND_HUM,
  //                                         PORT1_ADDR_PRESSURE};
  //int deviceAddrsPort2[NB_DEVICES_PORT2] = {PORT2_ADDR_TEMP_AND_HUM};
  //int bytesToRead =4;
//NOTE above remove

  unsigned char global_buffer[20]={0};
  // NOTE Array/vector of all the sensors instead
  Sensor* th1;
  Sensor* th2;
  Sensor* pr;
  //Fan* f;
  //std::vector<Sensor*> sensors;
  //Sensor* sensors[NB_DEVICES];

  void createSensorObjects();

public:
    ReadI2CDevices();

    void writeAll();
    std::string readAll();

    ~ReadI2CDevices();
};

#endif // READI2CDEVICES_HPP
