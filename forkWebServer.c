void createProcessPool(int max){  //NO ESTA LISTO
	pid_t pidFork = -1;
	int processNumber = 0;
	processPool = malloc(max*sizeof(int));
	while(processNumber<max){
		if(pidFork == 0){
			break;
		}else{
			processPool[processNumber++] = pidFork;
			waitpid(-1, NULL, WNOHANG);
			printf("SI\n");	
		}
		 
	}
}