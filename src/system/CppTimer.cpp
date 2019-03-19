
#include "CppTimer.h"


// Client side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define PORT     33333
// we will change it later
#define HOST    "192.168.1.2"
#define MAXLINE 1024



DemoTimer1::DemoTimer1(){
	this->r = new ReadI2CDevices();

  // do this part just once, this part is to setup and configure the socket
  //int sockfd;
  char buffer[MAXLINE];
  struct sockaddr_in     servaddr;

  if ( (this->sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
      perror("socket creation failed");
      exit(EXIT_FAILURE);
  }

  memset(&servaddr, 0, sizeof(servaddr));

  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(PORT);
  servaddr.sin_addr.s_addr =  inet_addr(HOST);
  // end of the first part
}


void DemoTimer1::timerEvent() {
  //call function ReadI2Cdevices
	fprintf(stdout,"Buh! ");
	fflush(stdout);


	r->writeAll();
  r->readAll();
	//std::thread sensorThread(&ReadI2CDevices::readAll, r);
	//sensorThread.join();

  // excute this part every time you want to send the data ( like every 200 ms or whatever)
  // we will send the data as a string, here its called (hello)
  // the data format is as following (inside_temp inside_hum outside_temp outside_hum)
  // and we seperate them by spaces as shown

  char *hello = "49 59 29 49";

  sendto(sockfd, (const char *)hello, strlen(hello),
         MSG_CONFIRM, (const struct sockaddr *) &servaddr,
              sizeof(servaddr));
  printf("Hello message sent.\n");
  // end of the second part

  // this is uselss code, but keep it in case
  // unsigned int n, len;
  // n = recvfrom(sockfd, (char *)buffer, MAXLINE,
  //             MSG_WAITALL, (struct sockaddr *) &servaddr,
  //             &len);
  // buffer[n] = '\0';
  // printf("Server : %s\n", buffer);

  close(sockfd);



}

DemoTimer1::~DemoTimer1(){
	delete this->r;


}
