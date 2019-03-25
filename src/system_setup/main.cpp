#include "I2C.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define I2C_PORT (char*)"/dev/i2c-1"
#define ADDR_TEMP_AND_HUM 0X27



unsigned char global_buffer[4]={0};
int main(int argc, const char* argv[] ){

  wiringPiSetupGpio();
  pinMode(11, OUTPUT);
  digitalWrite (11, LOW);
  sleep(1);

  global_buffer[0] = 0x00;
  global_buffer[1] = 0x00;
  global_buffer[2] = 0x18;


  digitalWrite (11, HIGH);

  I2C* bus = new I2C(I2C_PORT, ADDR_TEMP_AND_HUM);

  bus->writeI2C(3, global_buffer);

  sleep(1);

  // Set Set Alarm_High_On = 80% Humidity.
  //(Write 0x3333 to EEPROM Location 0x18).
  global_buffer[0] = 0x33;
  global_buffer[1] = 0x33;
  global_buffer[2] = 0x58;
  bus->writeI2C(3, global_buffer);

  //Set Alarm_High_Off = 75% Humidity.
  //(Write 0x3000 to EEPROM Location 0x19).
  global_buffer[0] = 0x00;
  global_buffer[1] = 0x30;
  global_buffer[2] = 0x59;
  bus->writeI2C(3, global_buffer);





  //bus->writeI2C();



}
