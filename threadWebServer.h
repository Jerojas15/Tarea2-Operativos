#ifndef _THREADWEBSERVER_H
#define _THREADWEBSERVER_H

#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

#define MAX_CONNECTIONS 100
#define true 1
#define false 0

int *processPool;
int prin_socket;
int current_threads;
int new_socket;

pthread_cond_t condition;
pthread_cond_t accept_condition;
pthread_mutex_t mutex;
pthread_mutex_t number_mutex;

//----- FUNCIONES PARA HILOS -----//
void startThreads(int max);

void *threadHandler();
void createThreads(int max);
void listeningConnections();
//----- FUNCIONES PARA HILOS -----//

#endif
