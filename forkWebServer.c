#include "forkWebServer.h"
#include "socket.h"

void startForkServer(int max){
	int new_conn, current_clients = 0;
	char *message;
	int p;
	for (int i = 0; i < max; ++i) {
	    p = fork();
	    if (p == 0) break;
	    if (p < 0) { printf("Error creando los procesos\n"); }
	}
	while (true) {
		if(current_clients==max){
			printf("Todos los procesos ocupados\n");
		}
	    new_conn = accept(prin_socket,NULL,NULL);
	    current_clients++;
	    printf("Se ha conectado un nuevo cliente\n");
	    if (new_conn < 0) { 
	    	printf("Error recibiendo una solicitud\n"); 
		}else {
	    	message = "Hola, soy el proceso host\n";
	        write(new_conn , message , strlen(message));
	        sleep(10);
	        close(new_conn);
	        current_clients--;
	    }
	}
}

int main(int argc, char *argv[]){
	int option, forks;
	int port = 8888;
	while((option = getopt(argc,argv,"n:wp:")) != -1){
		switch(option){
			case 'p':
				port = atoi(optarg);
				break;
			case 'n':
				forks = atoi(optarg);
				break;
			case 'w':
				printf("path\n");
				break;
		}
	}
	prin_socket = createSocket();
	printf("Server iniciado con exito\n");
	bindSocket(prin_socket, port);
	listen(prin_socket, MAX_CONNECTIONS);
	startForkServer(forks);
	return 0;
}