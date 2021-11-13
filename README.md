# Client-Server-Chat-Application
Client Server Chat Application Using Socket Programming

Note: While executing the client process, the IP address and PORT number of server is to be passed as command line argument.
THE PORT USED BY SERVER: 10010
Change it accordingly in server.c

OUTPUT
=======================================================

./client 127.0.0.1 10011
Please enter the message: Hello
Sending to SERVER: Hello
 
Received FROM SERVER: How`re you?
Please enter the message: I am good.

Sending to SERVER: I am good.
 
Received FROM SERVER: I am also fine.
Please enter the message: Thats great.     

Sending to SERVER: Thats great.

./server
Server Received: Hello
Please enter the reply: How`re you?
Server Received: I am good.
Please enter the reply: I am also fine.
Server Received: Thats great.
