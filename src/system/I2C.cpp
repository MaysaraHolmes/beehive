#include "I2C.hpp"




//Constructor to open the I2C bus and tell the kernel which I2C address it is
//NOTE change to function?
I2C::I2C(){

	//----- OPEN THE I2C BUS -----
	char *filename = (char*)"/dev/i2c-1"; // NOTE in lec: comment this and check with ls ""-l/ dev/i2c*"
	if ((file_i2c = open(filename, O_RDWR)) < 0)
	{
		//ERROR HANDLING: you can check errno to see what went wrong
		printf("Failed to open the I2C bus\n");
		return;
	}

	//NOTE lec: //tell the kernel which I2C address it is
	int addr = 0x27;          //<<<<<The I2C address of the slave NOTE Lec addr=0x58
	if (ioctl(file_i2c, I2C_SLAVE, addr) < 0)
	{
		printf("Failed to acquire bus access and/or talk to slave.\n");
		//ERROR HANDLING; you can check errno to see what went wrong
		return;
	}

}



void I2C::readI2C(int nbOfBytes){ //NOTE set default = length?

	//bitset<32> bitset1;

	//----- READ BYTES -----
	length = nbOfBytes;			//<<< Number of bytes to read
	if (read(file_i2c, buffer, length) != length)		//read() returns the number of bytes actually read, if it doesn't match then an error occurred (e.g. no response from the device)
	{
		//ERROR HANDLING: i2c transaction failed
		printf("Failed to read from the i2c bus.\n");
	}
	else
	{
		printf("\nData size buffer read: %d\n", sizeof(buffer));
		//printf("Data read: %s\n", buffer);
		//std::cout << std::hex << buffer << '\n';
		bitset<8> bitset1(buffer[0])
		bitset<8> bitset2(buffer[1])
		bitset<8> bitset3(buffer[2])
		bitset<8> bitset4(buffer[3])
		std::cout << "bitset1" << bitset1 << std::endl;
		std::cout << "bitset2" << bitset2 << std::endl;
		std::cout << "bitset3" << bitset3 << std::endl;
		std::cout << "bitset4" << bitset4 << std::endl; 
	}

}


int I2C::writeI2C(){

	//----- WRITE BYTES -----
	buffer[0] = 0x01;
	buffer[1] = 0x02;
	length = 2;			//<<< Number of bytes to write
	if (write(file_i2c, buffer, length) != length)		//write() returns the number of bytes actually written, if it doesn't match then an error occurred (e.g. no response from the device)
	{
		/* ERROR HANDLING: i2c transaction failed */
		printf("Failed to write to the i2c bus.\n");
		return -1;
	}
	printf("Succeeded writing");
	return 1;

}
