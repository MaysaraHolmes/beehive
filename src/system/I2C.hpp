#ifndef I2C_HPP
#define I2C_HPP

#include <unistd.h>				//Needed for I2C port
#include <fcntl.h>				//Needed for I2C port
#include <sys/ioctl.h>			//Needed for I2C port
#include <linux/i2c-dev.h>		//Needed for I2C port

#include <stdio.h>


//NOTE
//Do we need to OPEN THE I2C BUS and tell the kernel which I2C address it is many times. Or can I just put it in the constructor of the class?

//NOTE
// To&RH 0x27
// Pressure 0x60
// ADC 0x84
// Multiplexer 0x112 ??REMOVE?

class I2C{

	public:

		int file_i2c;
		//number of bytes to read
		int length;
		//data buffer
		unsigned char buffer[60] = {0}; //NOTE in lec: char buf[2];


    I2C();
    void readI2C(int nbOfBytes);
    int writeI2C();

};

#endif // I2C_HPP
