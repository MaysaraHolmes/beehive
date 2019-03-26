#include "Fan.hpp"


//Fan Fan::*saved_Fan_pointer = NULL;
int Fan::x =0;
Fan::Fan(int gpio, int interruptPin){
  //setFanPointer();
 // Fan::saved_Fan_pointer = this;
	Fan::x=10;
	this->gpio = gpio;
  this->interruptPin = interruptPin;
  wiringPiSetupGpio();
  pinMode(this->gpio, PWM_OUTPUT);
  pinMode(7, INPUT);
  int state = wiringPiISR(this->interruptPin, INT_EDGE_BOTH, helper_func0);
  //wiringPiISR(this->interruptPin, INT_EDGE_RISING, &start);
  //wiringPiISR(this->interruptPin, INT_EDGE_FALLING, &stop);
}
/*
void Fan::setFanPointer(){
	this->saved_Fan_pointer = this;
}*/

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
	std::cout << "gpio 7: " << ( digitalRead(7)) <<std::endl;
}
void Fan::onInterrupt(){
  if (digitalRead(this->interruptPin) == HIGH){
    start();
  }
  else{
    stop();
  }
}

Fan::~Fan(){
  //stop fan
  this->stop();
}
