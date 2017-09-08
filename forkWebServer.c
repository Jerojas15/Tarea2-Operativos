#include "forkWebServer.h"
#include "socket.h"
#include "requestHandler.h"

void startForkServer(int max){
	int new_conn;
	char *message;
	int p;
	int shmid;
   	int *shm;
   	int current_clients = 0;
	//shmid = shmget(2009, 30, 0666 | IPC_CREAT);
  	//shm = shmat(shmid, 0, 0);
  	//current_clients = shm;

	for (int i = 0; i < max; ++i) {
	    p = fork();
	    if (p == 0) break;
	    if (p < 0) { printf("Error creando los procesos\n"); }
	}
	while (true) {

	    new_conn = accept(prin_socket,NULL,NULL);

	    current_clients++;
		if(current_clients>=max){
			printf("Todos los procesos ocupados\n");
		}
	    printf("Se ha conectado un nuevo cliente\n");
	    if (new_conn < 0) { 
	    	printf("Error recibiendo una solicitud\n"); 
		}else {
			char * response = accept_request(new_conn, port);
			write(new_conn,response,strlen(response));
			sleep(10);
	        close(new_conn);
	        current_clients--;
	    }
	}
}

int main(int argc, char *argv[]){
	int option, forks;
	port = 0;
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
