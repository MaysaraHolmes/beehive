#include "ADC.hpp"



ADC::ADC(char* portI2C, int addrI2C){
  bus = new I2C(portI2C, addrI2C);
}


int ADC::writeI2C(){
  return bus->writeI2C(this->bytesToWrite);
}


void ADC::readI2C(unsigned char* global_buffer){

  //unsigned char* buffer =
  bus->readI2C(this->bytesToRead, global_buffer);

  int nbOfBytes = strlen((char*)global_buffer);
  if (nbOfBytes >=2 ){
    unsigned char bytes[2];
    for (int i=0; i<2; i++){
      bytes[i] = global_buffer[i];   //NOTE CHange the order?
    }
    std::bitset<16> bits(bytes);
    this->bitsetI2C = bits;
    std::cout << "print bitset: " << bits << std::endl;
  }
  std::cout << "size of buffer: " << nbOfBytes << std::endl;
  std::cout << "print buffer: " << global_buffer << std::endl;

}




ADC::~ADC(){
  delete bus;
}
