#include "Fan.hpp"


Fan* Fan::saved_Fan_pointer = NULL;

Fan::Fan(int gpio, int interruptPin){
  setFanPointer();
	this->gpio = gpio;
  this->interruptPin = interruptPin;
  wiringPiSetupGpio();
  pinMode(this->gpio, PWM_OUTPUT);
  pinMode(22, INPUT);
  int state = wiringPiISR(this->interruptPin, INT_EDGE_BOTH, onInterrupt);
  //wiringPiISR(this->interruptPin, INT_EDGE_RISING, &start);
  //wiringPiISR(this->interruptPin, INT_EDGE_FALLING, &stop);
}

void Fan::setFanPointer(){
	this->saved_Fan_pointer = this;
}

//range is 0-1024
void Fan::setPwm(int pwm_value){
  pwmWrite(this->gpio, pwm_value);
}

void Fan::start(){
  pwmWrite(this->gpio, 1023);
}

void Fan::stop(){
  pwmWrite(this->gpio, 0);
}

void Fan::readAlarmPin(){
	std::cout << "interruptpin: " << this->interruptPin <<std::endl;
	std::cout << "gpio 22: " << ( digitalRead(22)) <<std::endl;
}
void Fan::onInterrupt(){
	std::cout<< "Interrup!!!!! \n " << std::endl;
  if (digitalRead(saved_Fan_pointer->interruptPin) == HIGH){
    saved_Fan_pointer->start();
  }
  else{
    saved_Fan_pointer->stop();
  }
}

Fan::~Fan(){
  //stop fan
  this->stop();
}
