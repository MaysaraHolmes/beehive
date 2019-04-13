#include "ReadI2CDevices.hpp"



ReadI2CDevices::ReadI2CDevices(){
  createSensorObjects();
}

void ReadI2CDevices::createSensorObjects(){
  this->th1 = new TemperatureAndHumidity(I2C_PORT1, PORT1_ADDR_TEMP_AND_HUM);
  this->th2 = new TemperatureAndHumidity(I2C_PORT2, PORT2_ADDR_TEMP_AND_HUM);
  this->pr = new Pressure(I2C_PORT2, PORT2_ADDR_PRESSURE, this->global_buffer);
  //sensors.push_back(new TemperatureAndHumidity(I2C_PORT2, PORT1_ADDR_TEMP_AND_HUM));
}

void ReadI2CDevices::writeAll(){
  (this->th1)->writeI2C();
  (this->th2)->writeI2C();
  (this->pr)->writeI2C();
  /*for (Sensor* s : this->sensors){
    s->writeI2C();
  }*/
}

std::string ReadI2CDevices::readAll(){
  (this->th1)->readI2C(this->global_buffer);
  (this->th2)->readI2C(this->global_buffer);
  (this->pr)->readI2C(this->global_buffer);
  /*for (Sensor* s : this->sensors){
    s->readI2C(this->global_buffer);
  }*/

  /* Printing all the values:
  std::cout << "temp1: " << ((TemperatureAndHumidity*)th1)->getTemp() << std::endl;
  std::cout << "humidity1: " << ((TemperatureAndHumidity*)th1)->getHum() << std::endl;
  std::cout << "temp2: " << ((TemperatureAndHumidity*)th2)->getTemp() << std::endl;
  std::cout << "humidity2: " << ((TemperatureAndHumidity*)th2)->getHum() << std::endl;
  std::cout << "pressure: " << ((Pressure*)pr)->getPressure() << std::endl;
  std::cout << "temp_pressureSensor: " << ((Pressure*)pr)->getTemp() << std::endl;
  */
  std::string s = "";
  s += std::to_string( ((TemperatureAndHumidity*)th1)->getTemp()) + " " + std::to_string(((TemperatureAndHumidity*)th1)->getHum()) + " ";
  s += std::to_string(((TemperatureAndHumidity*)th2)->getTemp()) + " " +std::to_string( ((TemperatureAndHumidity*)th2)->getHum()) + " ";
	s+= std::to_string(((Pressure*)pr)->getPressure());
  return s;
}


ReadI2CDevices::~ReadI2CDevices(){
  delete th1;
  delete th2;
  delete pr;
  //for (Sensor* s : sensors){
    //delete s;
  //}
}
