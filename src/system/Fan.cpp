#include "Fan.hpp"


Fan::Fan(int gpio, int interruptPin){
  saved_Fan_pointer = this;
  this->gpio = gpio;
  this->interruptPin = interruptPin;
  wiringPiSetupGpio();
  pinMode(this->gpio, PWM_OUTPUT);
  pinMode(this->interruptPin, INPUT);
  wiringPiISR(this->interruptPin, INT_EDGE_BOTH, helper_func0);
  //wiringPiISR(this->interruptPin, INT_EDGE_RISING, &start);
  //wiringPiISR(this->interruptPin, INT_EDGE_FALLING, &stop);
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

static void helper_func0()
{
	std::cout << "in helper_func for pin 0: "<<std::endl;
  saved_Fan_pointer->onInterrupt();
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
