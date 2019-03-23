#include "Pressure.hpp"



Pressure::Pressure(char* portI2C, int addrI2C, unsigned char* global_buffer): Sensor(4,2, portI2C, addrI2C){
  //int addr[1] = {addrI2C};
  //bus = new I2C(portI2C, addr,1);
  this->readCoefficients(global_buffer);

}


void Pressure::readCoefficients(unsigned char* global_buffer){
  int16_t a0coeff;
  int16_t b1coeff;
  int16_t b2coeff;
  int16_t c12coeff;


  unsigned char buffer[10]={0};
  uint8_t write = (uint8_t)(0x04);
  buffer[0] = write;
  bus->writeI2C(1, buffer);

  bus->readI2C(8, global_buffer);
  //int nbOfBytes = strlen((char*)global_buffer);
  //std::cout << "nbOfBytes " << nbOfBytes << std::endl;

  // get the coefficients.  This only needs to be done once.
  // Note on C language: the << and >> operators perform bit shifting
  a0coeff = (( (uint16_t) (global_buffer[0]) << 8) | (global_buffer[1]) );
  b1coeff = (( (uint16_t) (global_buffer[2]) << 8) | (global_buffer[3]));
  b2coeff = (( (uint16_t) (global_buffer[4]) << 8) | (global_buffer[5]));
  c12coeff = (( (uint16_t) ((global_buffer[6]) << 8) | (global_buffer[7]))) >> 2;

  this->a0 = (float)a0coeff / 8;
  this->b1 = (float)b1coeff / 8192;
  this->b2 = (float)b2coeff / 16384;
  this->c12 = (float)c12coeff;
  this->c12 /= 4194304.0;
  std::cout << "printing coefficienter:  " << this->a0 << "  " << this->b1 << "  "<< this->b2 << "  "<< this->c12 << std::endl;
  std::cout << " " << std::endl;
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
  this->pressure = (( (uint16_t)(global_buffer[0]) << 8) | (global_buffer[1]) ) >> 6;
  std::cout << "\n PRESSURE BITS: " <<  (int)this->pressure << std::endl;
  this->temp = (( (uint16_t)(global_buffer[2]) << 8) | (global_buffer[3]) ) >> 6;


  this->pressureComp = this->a0 +
                       (this->b1 + this->c12 * (this->temp)) * (this->pressure) +
                       (this->b2) * (this->temp);
	std::cout << "pressureCOmp : " << this->pressureComp <<std::endl;
}


float Pressure::getPressure() {
  //return pressure in kiloPascals
  float k =  ((this->pressureComp) * ((115-50)/1023.0F)) + 50.0F;
  std::cout << "pressure i kPa: " << k << std::endl;
  return k;
}

float Pressure::getTemp() {
  //return temp in celsius degrees
  float t =  (  ( (float)(this->temp) - 498.0F) / (-5.35F)  ) + 25.0F ;
  std::cout << "temp : " << t << std::endl;
  return t;
}




Pressure::~Pressure(){
  //delete bus;
  //~Sensor() //?
}
