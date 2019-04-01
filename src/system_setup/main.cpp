/**
 * Configure the Honeywell HumidIcon™ Digital Humidity/Temperature Sensors,
 * trigger the alarm high on 80% humidity and off on 75% humidity
 */

#include "I2C.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define I2C_PORT (char*)"/dev/i2c-1"
#define ADDR_TEMP_AND_HUM 0X27
unsigned char global_buffer[4]={0};


int main(int argc, const char* argv[] ){

  global_buffer[2] = 0x00;
  global_buffer[1] = 0x00;
  global_buffer[0] = 0xA0;

  I2C* bus = new I2C(I2C_PORT, ADDR_TEMP_AND_HUM);
  while(  bus->writeI2C(3, global_buffer) != 1);
  sleep(1);

	global_buffer[2]= 0x00;
	global_buffer[1]= 0x00;
	global_buffer[0]= 0x18;
	bus->writeI2C(3, global_buffer);

  bus->readI2C(3, global_buffer);
  std::cout <<(int) global_buffer[0] << std::endl;
  std::cout << (int)global_buffer[1] <<std::endl;
  std::cout << (int)global_buffer[2] << std::endl;

  /*! \brief Set Set Alarm_High_On = 80% Humidity.
  *         (Write 0x3333 to EEPROM Location 0x18).
  */
  global_buffer[0] = 0x58;
  global_buffer[1] = 0x26;
  global_buffer[2] = 0x65;
  bus->writeI2C(3, global_buffer);

  /*! \brief Set Set Alarm_High_Off = 75% Humidity.
  *         (Write 0x3000 to EEPROM Location 0x19).
  */
  global_buffer[0] = 0x59;
  global_buffer[1] = 0x1F;
  global_buffer[2] = 0xFF;
  bus->writeI2C(3, global_buffer);

}
