//! A  class to control Fan
/*!
   Set different values for the Fan.
   Using a trigger pin connected to the humidity sensor inside the beehive,
   if the pin toggles (have threshold inside the sensor) it will trigger the onInterrupt() in this class and
   start or stop the Fan depending on if the pin goes to high or low.
*/
#ifndef FAN_HPP
#define FAN_HPP

#include <errno.h>
#include <wiringPi.h>


class Fan {

  private:
    //! A private variable.
    /*!
      Integer to hold the gpio pin the Fan is connected.
    */
    int gpio;
    //! A private variable.
    /*!
      Integer to hold the gpio pin the alarmpin form humidity sensor is connected.
    */
    int interruptPin;
    //! A private static variable.
    /*!
      Assuming we only have one fan to trigger.
      Need a static pointer to the object so that the static interrupt function know which fan to set.
      If we have multiple fans on different pins, this has to be changed to a list/vector/pointer.
    */
    static Fan *saved_Fan_pointer;

    //! Set the static Fan pointer saved_Fan_pointer
    /*!
      Called by the constructor.
      Saves the objects in the corresponding private variables.
      \sa Fan(int gpio = 18, int interruptPin=22), saved_Fan_pointer()
    */
    void setFanPointer();

  public:
    //! A constructor.
    /*!
      Set the private variables, default values is implemented
      \param gpio an integer giving the gpio pin the fan is connected.
      \param interruptPin an integer giving the gpio pin the alarmpin is connected.
    */
    Fan(int gpio = 18, int interruptPin=22);

    //! Set the PWM value to the fan
    /*!
      The PWM range is 0-1023.
    */
    void setPwm(int pwm_value);

    //! Start the Fan
    /*!
      Calls the setPWM(1023) to maximise the Fan
      \sa setPwm(int pwm_value)
    */
    void start();
    //! Stop the Fan
    /*!
      Calls the setPWM(0) to stop the Fan
      \sa setPwm(int pwm_value)
    */
    void stop();
    //! Static function triggers when the pin toggles.
    /*!
      Static to be called in real-time
      If the pin goes from high to low the stop() function is called
      If the pin goes from low to high the start() function is called
      \sa start() and stop()
    */
    static void onInterrupt();

    //! A destructor.
    /*!
      Stops the Fan
    */
    ~Fan();
};

#endif // FAN_HPP
