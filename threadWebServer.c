#include "threadWebServer.h"
#include "socket.h"
#include "requestHandler.h"
#include "httpRequestHandler.h"
//http://www.binarytides.com/socket-programming-c-linux-tutorial/
//http://www.thegeekstuff.com/2012/05/c-mutex-examples/?refcom
//https://gist.github.com/alexklibisz/7cffdfe90c97986f8393

void *threadHandler(){

	int new_socket_aux;
	char requestMsg[5000];
	char *response;

	while(true){
		pthread_mutex_lock(&mutex);
		while (new_socket == -1){
			pthread_cond_wait(&condition, &mutex);
		}
		new_socket_aux = new_socket;
		new_socket = -1;
		pthread_mutex_unlock(&mutex);
		if ( new_socket_aux > 0){
			response = accept_request(new_socket_aux, port, current_path);
			write(new_socket_aux, response, strlen(response));

			close(new_socket_aux);
			printf("Conexion finalizada correctamente.\n");
			pthread_mutex_lock(&number_mutex);
			current_threads--;
			pthread_mutex_unlock(&number_mutex);
			pthread_cond_signal(&accept_condition);
		}
	}
}

void createThreads(int max){
	current_threads = 0;
	pthread_t threads[max];
	for (int i = 0; i < max; i++){
		
		int err = pthread_create(&(threads[i]), NULL, threadHandler, NULL);
		if (err){
			printf("Error al iniciar un hilo.\n");
		}
	}
}

void listeningConnections(){
	if(listen(prin_socket, MAX_CONNECTIONS) == -1){
		printf("Se ha producido un error al intentar escuchar conexiones.\n");
	}
	printf("Pool de hilos creado\nListo para recibir conexiones\n");
}

void startThreads(int max){
	int new_conn;
	new_socket = -1;
	createThreads(max);
	listeningConnections();
	while(true){
		new_conn = accept(prin_socket,NULL,NULL);
		printf("Se ha conectado un nuevo cliente\n");
		if(new_conn<0){
			printf("Error al conectar el cliente\n");
		}else{
			pthread_mutex_lock(&mutex);
         	new_socket = new_conn;
         	pthread_mutex_unlock(&mutex);
         	pthread_cond_broadcast(&condition);
         	pthread_mutex_lock(&number_mutex);
         	current_threads++;
         	if (max == current_threads){ //si se llenan los hilos espera
         		printf("suave, todos estan ocupados\n");
            	pthread_cond_wait(&accept_condition, &number_mutex);
         		printf("dele, ya hay chance\n");
         	}
         	pthread_mutex_unlock(&number_mutex);
		}
	}
}



int main(int argc, char *argv[]){
	int option, read_size, threads;
	int new_socket, c;
	current_path = (char*)calloc(5000,sizeof(char));
	while((option = getopt(argc,argv,"n:w:p:")) != -1){
		switch(option){
			case 'p':
				port = atoi(optarg);
				break;
			case 'n':
				threads = atoi(optarg);
				break;
			case 'w':
				strcpy(current_path, optarg);
				break;
		}
	}
	prin_socket = createSocket();
	printf("Server iniciado con exito\n");
	bindSocket(prin_socket, port);
	startThreads(threads);
	return 0;
}