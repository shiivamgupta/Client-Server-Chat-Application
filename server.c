/*
=======================================================
Client Server Chat Application Using Socket: SERVER Code
Author: Shivam Gupta
=======================================================
*/
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

int main()
{
	int fd = 0;
	char buff[1024];
	char nbuff[1024];
	
	//Setup Buffer Array
	memset(buff, '0',sizeof(buff));	

	//Create Socket
	fd = socket(AF_INET, SOCK_STREAM, 0);
    	if(fd<0)
	{
		perror("Client Error: Socket not created succesfully");
		return 0;
	}

	//Structure to store details
	struct sockaddr_in server; 
	memset(&server, '0', sizeof(server)); 

	//Initialize	
	server.sin_family = AF_INET;
	server.sin_port = htons(10010); 
        server.sin_addr.s_addr = htonl(INADDR_ANY);
   

	bind(fd, (struct sockaddr*)&server, sizeof(server)); 

	int in;
	
	listen(fd, 10); 
	while(	in = accept(fd, (struct sockaddr*)NULL, NULL))
	{		
		int childpid,n;
		if ( (childpid = fork ()) == 0 ) 
		{
			close (fd);
		
			//Clear Zeroes
			bzero(buff,256);
			bzero(nbuff,256);
							
			while ( (n = recv(in, buff, 256,0)) > 0)  
			{
			
				printf("Server Received: %s",buff);
				
				printf("Please enter the reply: ");
		    		bzero(nbuff,256);
		    		fgets(nbuff,255,stdin);
				send(in, nbuff, strlen(nbuff), 0);
		
				bzero(buff,256);
										
			}
			close(in);
			exit(0);
		}
		
	}
}