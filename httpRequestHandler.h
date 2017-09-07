#ifndef _HTTPREQUESTHANDLER_H
#define _HTTPREQUESTHANDLER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Funcion: request
 * -----------------
 * Procedimiento el cual procesa la consulta del webServer y retorna una respuesta
 * utilizando el protocolo HTTP
 *
 * requestMsg: Mensaje siguiendo el formato HTTP para la consulta
 *
 * Retorno:
 * 			Mensaje siguiendo el formato HTTP
*/
char *request(char *requestMsg);


/*
 * Funcion: GetMethod
 * -------------------------
 * Procedimiento por defecto para las consultas bajo el metodo GET,
 * bucara el archivo asociado en la ultima direccion del path y lo
 * lo tratara como si fuera 'html'; en caso de que el path sea un directorio
 * y no un archivo, se buscara un archivo con el mismo nombre
 * 
 * Retorno:
 * 			Mensaje siguiendo el formato HTTP
 */
char *getMethod(char *method, char *path, int paramCount, char *parameters[], char *body);

/*
 * Funcion: PostMethod
 * -------------------------
 * Procedimiento por defecto para las consultas bajo el metodo POST,
 * crea un archivo html cuyo cuerpo sera los datos enviados 
 * [no se que podria hacer esto]
 * 
 * Retorno:
 * 			Mensaje siguiendo el formato HTTP
 */
char *postMethod(char *method, char *path, int paramCount, char *parameters[], char *body);

#endif