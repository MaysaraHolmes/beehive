#include "TimerEvent.hpp"

TimerEvent::TimerEvent(){
	this->r = new ReadI2CDevices();

  char buffer[MAXLINE];

  if ( (this->sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
      perror("socket creation failed");
      exit(EXIT_FAILURE);
  }
  memset(&(this->servaddr), 0, sizeof((this->servaddr)));
  (this->servaddr).sin_family = AF_INET;
  (this->servaddr).sin_port = htons(PORT);
  (this->servaddr).sin_addr.s_addr =  inet_addr(HOST);

}

void TimerEvent::timerEvent() {
	r->writeAll();
  std::string s = r->readAll();
	const char* hello = s.c_str();
  sendto(sockfd, hello, strlen(hello), MSG_CONFIRM,
	       (const struct sockaddr *) &(this->servaddr),
         sizeof((this->servaddr)));
}

TimerEvent::~TimerEvent(){
	delete this->r;
}
