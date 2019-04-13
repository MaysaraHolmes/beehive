//! A I2C class handling the I2C bus
/*!
   Handling I2C bus intended to allow multiple "slave"
	 digital chips to communicate with the master i.e Raspberry PI.
	 Every sensor connected to the bus has their own I2C-object.
*/

#ifndef I2C_HPP
#define I2C_HPP

#include <unistd.h>				//Needed for I2C port
#include <fcntl.h>				//Needed for I2C port
#include <sys/ioctl.h>			//Needed for I2C port
#include <linux/i2c-dev.h>		//Needed for I2C port
#include <stdio.h>
#include <iostream>


class I2C{

	private:
		//! A private variable.
    /*!
      To communicate with the I2C bus
    */
		int file_i2c;
		//! A private variable.
		/*!
			Used if you want to write to a peripheral, starting a conversation
		*/
		unsigned char buffer[5] = {0};

	public:
		//! A constructor.
    /*!
      Open the I2C bus and tell the kernel the I2C address of the slave.
      \param portI2C a char pointer holding the which I2C bus on the Raspberry the peripheral is connected to.
      \param slaveAddr an integer holding the address to the peripheral.
    */
		I2C(char* portI2C, int slaveAddr);
		//! Read data from the peripheral .
    /*!
      \param bytesToRead an integer gving numbers of bytes to read.
      \param global_buffer an unsigned char pointer where the data read is saved.
    */
    void readI2C(int bytesToRead, unsigned char* global_buffer);
		/*!
			\param length an integer gving numbers of bytes to write.
			\param buffer an unsigned char pointer pointing to the data to write.
		*/
		int writeI2C(int length, unsigned char* buffer);
		//! Write data to the peripheral .
		/*!
			Using the private buffer in the object to write default value
			\param length an integer gving numbers of bytes to write.
		*/
    int writeI2C(int length);


};

#endif // I2C_HPP
