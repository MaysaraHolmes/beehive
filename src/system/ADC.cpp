#include "ADC.hpp"



ADC::ADC(char* portI2C, int addrI2C){
  bus = new I2C(portI2C, addrI2C);
}


int ADC::writeI2C(){
  return bus->writeI2C(this->bytesToWrite);
}


void ADC::readI2C(){

  unsigned char* buffer = bus->readI2C(this->bytesToRead);

  int nbOfBytes = strlen((char*)buffer);
  if (nbOfBytes >=4 ){
    unsigned char bytes[4];
    for (int i=0; i<4; i++){
      bytes[i] = buffer[i];   //NOTE CHange the order?
    }
    std::bitset<32> bits(bytes);
    this->bitsetI2C = bits;
    std::cout << "print bitset: " << bits << std::endl;
  }
  std::cout << "size of buffer: " << nbOfBytes << std::endl;
  std::cout << "print buffer: " << buffer << std::endl;

}




ADC::~ADC(){
  delete bus;
}
