#include "httpClient.h"

int initSocket(){
	sock = socket(AF_INET , SOCK_STREAM , 0);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8080 );
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        printf("Error al conectar con el server.\n");  
    }else{
    	printf("Conexion realizada con exito.\n");
	}
	return sock;
}

int main(int argc, char *argv[]){
	int option;
	char *current_path = (char *)calloc(5000, sizeof(char));
	char *response = (char *)calloc(5000, sizeof(char));
	while((option = getopt(argc,argv,"u:")) != -1){
		switch(option){
			case 'u':
				strcpy(current_path, optarg);
				break;
		}
	}
	sock = initSocket();

	char * message = (char *)calloc(5000, sizeof(char)); ////AQUI VA EL REQUEST

	send(sock , message , strlen(message) , 0);
	recv(sock , response , 2000 , 0);//AQUI RECIBE EL RESULTADO DEL REQUEST Y LO GUARDA EN RESPONSE
	printf("%s\n", response);
	return 0;
}