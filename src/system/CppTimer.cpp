
#include "CppTimer.h"




#include "boost/asio.hpp"
using namespace boost::asio;




DemoTimer1::DemoTimer1(){
	this->r = new ReadI2CDevices();
}


void DemoTimer1::timerEvent() {
  //call function ReadI2Cdevices
	fprintf(stdout,"Buh! ");
	fflush(stdout);

	io_service io_service;
	ip::udp::socket socket(io_service);
	ip::udp::endpoint remote_endpoint;

	r->writeAll();
	r->readAll();


	socket.open(ip::udp::v4());
	remote_endpoint = ip::udp::endpoint(ip::address::from_string("192.168.0.4"), 9000);
	boost::system::error_code err;
	socket.send_to(buffer("Jane Doe", 8), remote_endpoint, 0, err);
	socket.close();



}

DemoTimer1::~DemoTimer1(){
	delete this->r;


}
