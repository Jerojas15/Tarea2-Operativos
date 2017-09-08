#include "httpRequestHandler.h"
#include "socket.h"
char *ftp_protocol(){
	char *response;
	response = "ftp\n";
	return response;
}

char *smtp_protocol(){
	char *response;
	response = "smtp\n";
	return response;
}

char *dns_protocol(){
	char *response;
	response = "dns\n";

	return response;
}

char *telnet_protocol(){
	char *response;
	response = "telnet\n";

	return response;
}

char *ssh_protocol(){
	char *response;
	response = "################################################\n#           WELCOME TO THE SSH SERVER          #\n#        THIS IS A SECURE CONNECTION           #\n#        ONLY FOR AUTORIZED PERSONAL           #\n#          IF NOT PLEASE EXIT NOW              #\n################################################\n";
	return response;
}

char *http_protocol(int socket){
	char *response;
	char requestMsg[5000];
	recv(socket , requestMsg, 5000 , 0);
	printf("---------------------------------\n%s---------------------------------\n", requestMsg);     
	response = request(requestMsg);
	return response;
}

char *snmp_protocol(){
	char *response;
	response = "snmp\n";

	return response;
}


char *accept_request(int socket, int port){
	char * response;
	switch(port){
		case 20:
		case 21:
			response = ftp_protocol();
			break;
		case 25:
			response = smtp_protocol();
			break;
		case 53:
			response = dns_protocol();
			break;
		case 23:
			response = telnet_protocol();
			break;
		case 2022:
			response = ssh_protocol();
			break;
		case 8080:
			response = http_protocol(socket);
			break;
		case 161:
			response = snmp_protocol();
			break;
		default:
			response = "Protocolo no especificado\n";
	}
	return response;
}