#ifndef _SOCKET_H
#define _SOCKET_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

struct sockaddr_in server, client;
int port;
//----- FUNCIONES DEL SERVER -----//
int createSocket();
void bindSocket(int socket, int port);
//----- FUNCIONES DEL SERVER -----//

#endif