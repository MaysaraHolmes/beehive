#ifndef I2C_HPP
#define I2C_HPP

#include <unistd.h>				//Needed for I2C port
#include <fcntl.h>				//Needed for I2C port
#include <sys/ioctl.h>			//Needed for I2C port
#include <linux/i2c-dev.h>		//Needed for I2C port
#include <stdio.h>
#include <iostream>


class I2C{

	public:

		int file_i2c;
		//Constructor, open the I2C bus and tell the kernel the address of the slave
		I2C(char* portI2C, int slaveAddr);

    void readI2C(int bytesToRead, unsigned char* buffer);
    int writeI2C(int length);
		int writeI2C(int length, unsigned char* buffer);

};

#endif // I2C_HPP
