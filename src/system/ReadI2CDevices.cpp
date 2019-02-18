#include "ReadI2CDevices.hpp"



ReadI2CDevices::ReadI2CDevices(){
  //this->bus1 = new I2C(I2C_PORT1, deviceAddrsPort1, NB_DEVICES_PORT1);
  //this->bus2 = new I2C(I2C_PORT2, deviceAddrsPort2, NB_DEVICES_PORT2);
  createSensorObjects();
}
void ReadI2CDevices::createSensorObjects(){
  //save to private list?
  //TemperatureAndHumidity th1(I2C_PORT1, ADDR_TEMP_AND_HUM);
  this->th1 = new TemperatureAndHumidity(I2C_PORT2, PORT1_ADDR_TEMP_AND_HUM);
}




void ReadI2CDevices::writeAll(){
  //for all sensors in this-> list
    //sensor.writeI2C;

  int i = (this->th1)->writeI2C();
}



void ReadI2CDevices::readAll(){//make attribute instead
  //(this->bus1)->readI2C(this->bytesToRead, global_buffer);
  //(this->bus1)->readI2C(this->bytesToRead, global_buffer);
  //maybe add one for each device?

  (this->th1)->readI2C(this->global_buffer);

  std::cout << "status: " << th1->getStatus() << std::endl;
  std::cout << "temp: " << th1->getTemp() << std::endl;
  std::cout << "humidity: " << th1->getHum() << std::endl;
}


ReadI2CDevices::~ReadI2CDevices(){
  //delete this->bus1;
  //delete this->bus2;

  //delete s i sensors;
  delete th1;
}
