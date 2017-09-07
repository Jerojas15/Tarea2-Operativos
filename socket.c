#include "socket.h"

int createSocket(){
	int socketId = socket(AF_INET , SOCK_STREAM , 0);
	if (socketId == -1){
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
	    printf("Error durante el bind\n");
	}else{
		printf("Escuchando el puerto %i\n",port);	
	}
}