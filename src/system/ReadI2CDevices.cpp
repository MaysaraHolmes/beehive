#include "ReadI2CDevices.hpp"



ReadI2CDevices::ReadI2CDevices(){
  this->bus1 = new I2C(I2C_PORT1, deviceAddrsPort1, NB_DEVICES_PORT1);
  this->bus2 = new I2C(I2C_PORT2, deviceAddrsPort2, NB_DEVICES_PORT2);
}



void ReadI2CDevices::readAll(unsigned char* global_buffer){//make attribute instead
  (this->bus1)->readI2C(this->bytesToRead, global_buffer);
  //(this->bus1)->readI2C(this->bytesToRead, global_buffer);
  //maybe add one for each device?

}


ReadI2CDevices::~ReadI2CDevices(){
  delete this->bus1;
  delete this->bus2;
}
