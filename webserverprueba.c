#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int option;
	while((option = getopt(argc,argv,"n:x")) != -1){
		if(option=='n'){
			printf("si");
		}
		if(option=='x'){
			printf("si2");
		}
	}
	return 0;
}