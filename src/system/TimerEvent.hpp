//! A  class which is triggered by the CppTimer.h
/*!
   Get the combined data read from sensors and send it through UDP to display
   Includes the client side implementation of UDP client-server model

*/
#ifndef TIMEREVENT_HPP
#define TIMEREVENT_HPP

#include "CppTimer.h"
#include "ReadI2CDevices.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string>

#define PORT     33333
#define HOST    "127.0.0.1"
#define MAXLINE 1024

class TimerEvent : public CppTimer {
	public:
    //! A constructor.
    /*!
      Create a new ReadI2CDevices-object and saves it to the corresponding private variable.
      Setup and configure the socket
    */
		TimerEvent();

    //! A destructor.
    /*!
      Deallocates memory from heap
    */
		~TimerEvent();
	private:
    //! A private variable.
    /*!
      Object to get all the gathered sensor data.
    */
		ReadI2CDevices* r;

    //! A private variable.
    /*!
      The socket created in the constructor
    */
		int sockfd;

    //! A private variable.
    /*!
      Struct containing the server address, port number and host number
    */
		struct sockaddr_in     servaddr;

    //! A private member
    /*!
      Called by the CppTimer.h
      Get a string of all the sensor data and send it to the server
    */
		void timerEvent();


};

#endif
