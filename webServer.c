#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
//#include <pthread.h>


//http://www.binarytides.com/socket-programming-c-linux-tutorial/
struct sockaddr_in server, client;

int createSocket(){
	int socketId;
   
	//Create socket
	socketId = socket(AF_INET , SOCK_STREAM , 0);
	if (socketId == -1)
	{
	    printf("Error al crear el socket");
	}
	printf("Socket creado con exito\n");
	return socketId;
}

void bindSocket(int socket, int port){
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(port);     
	//Bind
	if( bind(socket,(struct sockaddr *)&server , sizeof(server)) < 0)
	{
	    printf("error durante el bind");
	}
	printf("bind completado en el puerto %i\n",port);
}

int main(int argc, char *argv[]){
	int option, read_size;
	int socket, new_socket, c, port = 8888;
	char *message, client_message[2000], *answer;
	while((option = getopt(argc,argv,"p:tf")) != -1){
		switch(option){
			case 'p':
				port = atoi(optarg);
		}
	}

	socket = createSocket();
	bindSocket(socket, port);
	printf("Server iniciado con exito\n");
	listen(socket, 3);
     
    //Accept and incoming connection
    puts("Esperando conexiones...");
    c = sizeof(struct sockaddr_in);
	while( (new_socket = accept(socket, (struct sockaddr *)&client, (socklen_t*)&c)) ){
        puts("Conexion aceptada");
         
        //Reply to the client
        message = "Hola!\n";
        answer = "OK\n";
        write(new_socket , message , strlen(message));//responde al cliente
         
        while( (read_size = recv(new_socket , client_message , 2000 , 0)) > 0 )
    	{
        	//Send the message back to client
        	write(new_socket , answer , strlen(answer));
        	bzero(client_message, read_size);
    	}
    }
     
    if (new_socket<0)
    {
        perror("fallo al conectar");
        return 1;
    }
    //close(socket);
	return 0;
}