THREADHEADERS = threadWebServer.h socket.h
THREADFILES = threadWebServer.c socket.c
FORKHEADERS = forkWebServer.c socket.c
FORKFILES = forkWebServer.h socket.h
LIBRARYS = -pthread
EXE = prethread-webserver
EXE2 = preforked-webserver

all: 
	gcc $(LIBRARYS) $(THREADHEADERS) $(THREADFILES) -o $(EXE)
	gcc $(FORKHEADERS) $(FORKFILES) -o $(EXE2)

run_default_pre-thread:
	./$(EXE) -p 8888 -t 10

run_default_pre-fork:
	./$(EXE) -p 8888 -f 10	

clean:
	rm $(EXE)
	rm $(EXE2)