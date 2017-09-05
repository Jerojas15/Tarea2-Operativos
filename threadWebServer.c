#include "threadWebServer.h"
#include "socket.h"
#include "httpRequestHandler.h"
//http://www.binarytides.com/socket-programming-c-linux-tutorial/
//http://www.thegeekstuff.com/2012/05/c-mutex-examples/?refcom
//https://gist.github.com/alexklibisz/7cffdfe90c97986f8393

void *threadHandler(){
	int new_socket_aux;
	char requestMsg[5000];
	while(true){
		pthread_mutex_lock(&mutex);
		while (new_socket == -1){
			pthread_cond_wait(&condition, &mutex);
		}
		new_socket_aux = new_socket;
		new_socket = -1;
		pthread_mutex_unlock(&mutex);
		if ( new_socket_aux > 0){
			printf("\n\nAQUI SE PROCESA EL MENSAJE\n\n");
			recv(new_socket_aux , requestMsg, 2000 , 0);
			printf("%s\n", requestMsg);
			char *response = request(requestMsg);
			


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
	int new_socket, c, port = 8888;
	while((option = getopt(argc,argv,"n:wp:")) != -1){
		switch(option){
			case 'p':
				port = atoi(optarg);
				break;
			case 'n':
				threads = atoi(optarg);
				break;
			case 'w':
				printf("path\n");
				break;
		}
	}
	prin_socket = createSocket();
	printf("Server iniciado con exito\n");
	bindSocket(prin_socket, port);
	startThreads(threads);
	/*
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
    //close(socket);*/
	return 0;
}