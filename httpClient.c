#include "httpClient.h"

int initSocket(int port){
	sock = socket(AF_INET , SOCK_STREAM , 0);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( port );
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        printf("Error al conectar con el server.\n");  
    }
	return sock;
}

int main(int argc, char *argv[]){
	int option, port;
	char *current_path = (char *)calloc(5000, sizeof(char));
	char *response = (char *)calloc(5000, sizeof(char));
	while((option = getopt(argc,argv,"u:i:p:")) != -1){
		switch(option){
			case 'u':
				strcpy(current_path, optarg);
				break;
			case 'i':
				break;
			case 'p':
				port = atoi(optarg);
				break;
		}
	}
	sock = initSocket(port);
	if(sock <0){
		return 0;
	}
	char * message = (char *)calloc(5000, sizeof(char)); ////AQUI VA EL REQUEST
	if(port == 8080){
		send(sock,message,strlen(message),0);
	}
	recv(sock , response , 2000 , 0);//AQUI RECIBE EL RESULTADO DEL REQUEST Y LO GUARDA EN RESPONSE
	printf("%s\n", response);
	return 0;
}