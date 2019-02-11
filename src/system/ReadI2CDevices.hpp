#ifndef READI2CDEVICES_HPP
#define READI2CDEVICES_HPP

#include "I2C.hpp"

#include <stdio.h>
#include <iostream>
#include <bitset>
#include <cstring>  // strlen()

#define I2C_PORT1 (char*)"/dev/i2c-1"
#define I2C_PORT2 (char*)"/dev/i2c-3"

#define NB_DEVICES_PORT1 2
#define NB_DEVICES_PORT2 1

#define PORT1_ADDR_TEMP_AND_HUM 0X27
#define PORT1_ADDR_PRESSURE 0X00

#define PORT2_ADDR_TEMP_AND_HUM 0X27



class ReadI2CDevices{

private:
  I2C* bus1;
  I2C* bus2;

  int deviceAddrsPort1[NB_DEVICES_PORT1] = {PORT1_ADDR_TEMP_AND_HUM,
                                           PORT1_ADDR_PRESSURE};
  int deviceAddrsPort2[NB_DEVICES_PORT2] = {PORT2_ADDR_TEMP_AND_HUM};

  int bytesToRead =4;


public:


    ReadI2CDevices();

    void readAll(unsigned char* global_buffer);


    ~ReadI2CDevices();

};

#endif // READI2CDEVICES_HPP
