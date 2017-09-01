#ifndef _WEBSERVER_H
#define _WEBSERVER_H

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

#define MAX_CONNECTIONS 100
#define true 1
#define false 0

struct sockaddr_in server, client;
int *processPool;
int prin_socket;
int current_threads;
int new_socket;

pthread_cond_t condition;
pthread_cond_t accept_condition;
pthread_mutex_t mutex;
pthread_mutex_t number_mutex;

//----- FUNCIONES DEL SERVER -----//
int createSocket();
void bindSocket(int port);
//----- FUNCIONES DEL SERVER -----//



//----- FUNCIONES PARA HILOS -----//
void startThreads(int max);

void *threadHandler();
void createThreads(int max);
void listeningConnections();
//----- FUNCIONES PARA HILOS -----//

#endif