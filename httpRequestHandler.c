#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "httpRequestHandler.h"

char NOT_IMPLEMENTED[] = "HTTP/1.1 501 Not Implemented";


int headerCount(char *requestMsg){

	char c1, c2;
	int count, ith;
	
	c1 = 1;
	c2 = 1;
	count = 0;
	ith = 0;
	while(c1){
		c1 = requestMsg[ith];
		c2 = requestMsg[ith+1];
		if(c1 == '\n'){
			
			if(c1 == c2 || !c2)
				break;

			count++;
		}
		ith++;
	}
	return count;
}


int paramCount(char *path){

	char c, *s;
	int count, ith;

	count = 0;
	s = strchr(path, '?');
	if(s != NULL){

		c = 1;
		count++;
		ith = 0;
		while(c){
			
			c = s[ith];
			if(c == '&')
				count++;

			ith++;
		}
	}
	return count;
}

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
char *request(char *requestMsg){

	int paramsCount, headersCount, count, ith;
	char *method, *path, **parameters, *httpVersion, **headers, *body, *s;

	headersCount = headerCount(requestMsg);

	method = strtok(requestMsg, " ");
	path = strtok(NULL, " ");
	httpVersion = strtok(NULL, "\n");

	headers = (char**)malloc(headersCount * sizeof(char*));

	for(int i = 0; i < headersCount; i++){

		headers[i] = strtok(NULL, "\n");
	}

	body = strtok(NULL, "\n\0");
	if(body)
		body += 1;						//Ignorar el segundo \n despues de los headers si existe
	
	paramsCount = paramCount(path); 	//Si el path presenta parametros, aqui se parsean
	if(paramsCount > 0){

		path = strtok(path, "?");
		parameters = (char**)malloc(paramsCount * sizeof(char*));

		count = paramsCount;
		count--;
		ith = 0;
		while(count--){

			parameters[ith] = strtok(NULL, "&");
			ith++;
		}
		parameters[ith] = strtok(NULL, "\0");
	}


	if(!strcmp(method, "GET")){
		
		getMethod(method, path, paramsCount, parameters, body);

	}else if(!strcmp(method, "POST")){
		
		postMethod(method, path, paramsCount, parameters, body);

	}else {
		
		printf("Metodo <%s> no soportado\n", method);
		
		return NOT_IMPLEMENTED;
	}

	printf("\n");
	printf("%s\n", method); printf("%s\n", path);
	for(int i = 0; i < paramsCount; i++) printf("%s\n", parameters[i]);
	printf("%s\n", httpVersion);
	for(int i = 0; i < headersCount; i++)  printf("%s\n", headers[i]);
	if(body)
		printf("%s\n", body);

	return NULL;
}

/*
 * Funcion: getMethod
 * -------------------------
 * Procedimiento por defecto para las consultas bajo el metodo GET,
 * bucara el archivo asociado en la ultima direccion del path y lo
 * lo tratara como si fuera 'html'; en caso de que el path sea un directorio
 * y no un archivo, se buscara un archivo con el mismo nombre
 * 
 * Retorno:
 * 			Mensaje siguiendo el formato HTTP
 */
char *getMethod(char *method, char *path, int paramCount, char *parameters[], char *body){
	printf("Metodo GET\n");
}

/*
 * Funcion: postMethod
 * -------------------------
 * Procedimiento por defecto para las consultas bajo el metodo POST,
 * crea un archivo html cuyo cuerpo sera los datos enviados 
 * [no se que podria hacer esto]
 * 
 * Retorno:
 * 			Mensaje siguiendo el formato HTTP
 */
char *postMethod(char *method, char *path, int paramCount, char *parameters[], char *body){
	printf("Metodo POST\n");
}
/*
int main(int argc, char *argv[]){
	char *s = 	"GET /asd/d?v=1&v1=2 http/1.1\nheader 1\nheader 2\nheader 3\nheader 4\n\nbody\n\0";
	
	
	char *req = malloc((strlen(s) + 1) * sizeof(char));
	strcpy(req, s);

	request(req);
}*/