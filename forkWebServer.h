#ifndef _FORKWEBSERVER_H
#define _FORKWEBSERVER_H

#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

#define MAX_CONNECTIONS 100
#define true 1
#define false 0

int prin_socket;
char *current_path;
void startForkServer(int max);

#endif