#include "Fan.hpp"



Fan::Fan(int gpio, int interruptPin){
  num = 0;
  saved_Fan_pointer[num] = this;
  this->gpio = gpio;
  this->interruptPin = interruptPin;
  wiringPiSetupGpio();
  pinMode(this->gpio, PWM_OUTPUT);
  pinMode(this->interruptPin, INPUT);
  int state = wiringPiISR(this->interruptPin, INT_EDGE_BOTH, helper_function[num]);
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
