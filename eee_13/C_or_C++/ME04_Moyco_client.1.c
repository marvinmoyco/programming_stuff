#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <signal.h>
#include <ctype.h>
/* 
	Jan Marvin D. Moyco 2015-09359 BS ECE EEE 13 TLMWFU
	ME 4 - TCP Socket Programming
		This Machine Exercise is a bidirectional connection of a server and a client. 
		NOTE: This is the CLIENT SIDE of the code.

*/
void sig_func(int signum)
{
	if(signum == SIGINT)
	{
		printf("Client forcibly terminates\n");
		exit(0);
	}
	
}

int main(int argc, char **argv)
{
  int sockfd;										//Variable Declaration/Initialization
  int recvfromstatus;
  struct sockaddr_in servaddr;
  socklen_t len = sizeof(servaddr);
  char mesg[1024];
  int cstat = 0;
  int portnum=0;
  if(argc!=3){ 										//Error checking for command-line arguments so that the IP Address of the server is indicated
	printf("Usage: %s <ip_addr> <port_number>\n",argv[0]);
	return -EINVAL; 
  }
	if(signal(SIGINT,sig_func) == SIG_ERR){
	
		printf("Error creating signal\n");
		exit(0);
	}
	portnum = atoi(argv[2]);
	if(isdigit(portnum)==0)
	{
	  printf("Port number is not digits. Try again\n");
	  return -1;
	}
	else{
	 if(portnum<10000)
	 {
	   printf("Please use ports greater than 10000\n");
	   return -1;
	 }
	}
  sockfd = socket(PF_INET,SOCK_STREAM,0);						//Creation of socket
  if(sockfd<0) {									//Error checking of socket()
	perror("socket: ");
	return -EIO;
  }

  bzero(&servaddr, sizeof(servaddr));							//Configuration of IP adress and port number so that it can be used for connect()
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(portnum);
  inet_pton(AF_INET,argv[1],&servaddr.sin_addr);

  //not present in udp clients
  cstat =connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));			//Connecting to the server
  	if(cstat<0){									//Error checking of connect()
	perror("connect: ");
	close(sockfd);
	return -EIO;
  }

  while(1){										//While loop for sending and receiving string
	
	fgets(mesg,sizeof(mesg),stdin);							//Getting the message string from the user
	fflush(stdout);
	printf("Sending to server: %s",mesg);						//Printing of the message 
  	if((sendto(sockfd,mesg,strlen(mesg),0,(const struct sockaddr *)&servaddr,len)) == -1)	//Sending of the message to the socket fd and error checking of sendto()
  	//if((send(sockfd,mesg,strlen(mesg),0)) == -1)
  	{
  	            fprintf(stderr, "Error Sending Message\n");
                close(sockfd);
                exit(1);
  	    
  	}
  	else{										//If no error, then the client will receive the parsed message from the server
                recvfromstatus = recvfrom(sockfd,mesg, sizeof(mesg),0,(struct sockaddr *)&servaddr,&len);	//recvfrom() from the server
              // recvfromstatus = recv(sockfd,mesg, sizeof(mesg),0);
                if ( recvfromstatus<= 0 )						//Error checking of recvfrom
                {
                        printf("Error Connection to server\n");
                        break;
                }
                fflush(stdout);
                printf("Message received from server: %s", mesg);			//Printing of the parsed message string from the server
		int strstat = strcmp(mesg,"exit\n");					//If the message string is 'exit', then
  	    	if( strstat== 0)							//the client side will exit the program.
		{
			fflush(stdout);
			printf("Client Terminating\n");
			close(sockfd);
			exit(0);
		}
  	    
  	    
  	}
	
  }
  printf("Client is terminating\n");
  close(sockfd);									//Closing of the socket fd after the sending and receiving is complete.
  return 0;
}
