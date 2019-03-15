#include "Pressure.hpp"



Pressure::Pressure(char* portI2C, int addrI2C): Sensor(4,2, portI2C, addrI2C){
  //int addr[1] = {addrI2C};
  //bus = new I2C(portI2C, addr,1);
}


int Pressure::writeI2C(){
  return bus->writeI2C(this->bytesToWrite);
}



void Pressure::readI2C(unsigned char* global_buffer){



  //NOTE go to bookmark to see example
  bus->readI2C(this->bytesToRead, global_buffer);
  int nbOfBytes = strlen((char*)global_buffer);
  std::cout << "nbOfBytes " << nbOfBytes << std::endl;

  //seperate the different bits read
  this->pressureBits = (((uint16_t)(global_buffer[0]) << 8) | (global_buffer[1]) ) >> 6;
  std::cout << "\n PRESSURE BITS: " <<  (int)this->pressureBits << std::endl;
  this->tempBits = ( ( (uint16_t)(global_buffer[2]) << 8) | (global_buffer[3]) ) >> 6;

}


float Pressure::getPressure() {
  return ((unsigned int)this->pressureBits) * ((115-50)/1023) + 50;
}

float Pressure::getTemp() {
  return (  ((float)(this->tempBits) - 498.0) / (-5.35)  ) + 25.0 ;
}



Pressure::~Pressure(){
  //delete bus;
  //~Sensor() //?
}
