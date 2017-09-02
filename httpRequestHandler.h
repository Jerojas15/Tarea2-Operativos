#ifndef _HTTPREQUESTHANDLER_H
#define _HTTPREQUESTHANDLER_H

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
 * Funcion: methodHandler
 * ----------------------
 * Procedimiento el cual se encarga de manejar las consultas, si existe una consulta
 * en especificada con un procedimiento, llamara ese procedimiento; por lo contrario
 * se llamara el procediemiento por defecto
 *
 * method:  GET, POST
 * path: 	Direccion al recurso
 * argc: 	Numero de parametros [puede ser 0]
 * argv: 	Arreglo con los parametros [puede ser nulo]
 *
 * Retorno:
 * 			Mensaje siguiendo el formato HTTP
 */
char *methodHandler(char *method, char *path, int argc, char *argv[]);

/*
 * Funcion: defaultGetMethod
 * -------------------------
 * Procedimiento por defecto para las consultas bajo el metodo GET,
 * bucara el archivo asociado en la ultima direccion del path y lo
 * lo tratara como si fuera 'html'; en caso de que el path sea un directorio
 * y no un archivo, se buscara un archivo con el mismo nombre
 * 
 * Retorno:
 * 			Mensaje siguiendo el formato HTTP
 */
char *defaultGetMethod();

/*
 * Funcion: defaultPostMethod
 * -------------------------
 * Procedimiento por defecto para las consultas bajo el metodo POST,
 * crea un archivo html cuyo cuerpo sera los datos enviados 
 * [no se que podria hacer esto]
 * 
 * Retorno:
 * 			Mensaje siguiendo el formato HTTP
 */
char *defaultPostMethod();

#endif