#include "I2C.hpp"


I2C::I2C(char* portI2C, int addrI2C){

	//----- OPEN THE I2C BUS -----
	char *filename = (char*)portI2C;
	if ((file_i2c = open(filename, O_RDWR)) < 0)
	{
		//ERROR HANDLING: you can check errno to see what went wrong
		printf("Failed to open the I2C bus\n");
		return;
	}

	//tell the kernel the I2C address of the slave
	int addr = addrI2C;
	if (ioctl(file_i2c, I2C_SLAVE, addr) < 0)
	{
		printf("Failed to acquire bus access and/or talk to slave.\n");
		//ERROR HANDLING; you can check errno to see what went wrong
		return;
	}

}



void I2C::readI2C(int bytesToRead, unsigned char* global_buffer){

	//----- READ BYTES -----
	//length = bytesToRead;			//<<< Number of bytes to read
	//std::cout << "read bytes: " << read(file_i2c, global_buffer, bytesToRead) << std::endl;
	std::cout << "read bytes: " << read(file_i2c, buffer, bytesToRead) << std::endl;
	if (read(file_i2c, global_buffer, bytesToRead) != bytesToRead)		//read() returns the number of bytes actually read, if it doesn't match then an error occurred (e.g. no response from the device)
	{
		//ERROR HANDLING: i2c transaction failed

		printf("Failed to read from the i2c bus.\n");
		//return (unsigned char*)"-1"; //NOTE change?
	}
	else
	{
		//printf("\nData size buffer read: %d\n", sizeof(buffer));
		//printf("Data read: %s\n", buffer);
		//std::cout << std::hex << buffer << '\n';
		std::bitset<8> bitset1(buffer[0]);
		std::bitset<8> bitset2(buffer[1]);
		std::bitset<8> bitset3(buffer[2]);
		std::bitset<8> bitset4(buffer[3]);
		std::cout << "bitset1: " << bitset1 << std::endl;
		std::cout << "bitset2: " << bitset2 << std::endl;
		std::cout << "bitset3: " << bitset3 << std::endl;
		std::cout << "bitset4: " << bitset4 << std::endl;
		//return bitset? or buffer?
		//return buffer;//return a copy?
	}

}


int I2C::writeI2C(int length){//NOTE set default values if not sent in

	//----- WRITE BYTES -----
	buffer[0] = 0x01;
	buffer[1] = 0x02;
	//int length = 2;			//<<< Number of bytes to write
	if (write(file_i2c, buffer, length) != length)		//write() returns the number of bytes actually written, if it doesn't match then an error occurred (e.g. no response from the device)
	{
		/* ERROR HANDLING: i2c transaction failed */
		printf("Failed to write to the i2c bus.\n");
		return -1;
	}
	printf("Succeeded writing");
	return 1;

}
