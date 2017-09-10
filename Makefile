THREADHEADERS = threadWebServer.h socket.h
THREADFILES = threadWebServer.c socket.c

GLOBALHEADERS = httpRequestHandler.h requestHandler.h
GLOBARLFILES = httpRequestHandler.c requestHandler.c

FORKHEADERS = forkWebServer.c socket.c
FORKFILES = forkWebServer.h socket.h

LIBRARYS = -pthread

HTTPHEADERS = httpClient.h
HTTPFILES = httpClient.c

EXE = prethread-webserver
EXE2 = preforked-webserver
EXE3 = httpClient

all: 
	gcc $(LIBRARYS) $(THREADHEADERS) $(GLOBALHEADERS) $(GLOBARLFILES) $(THREADFILES) -o $(EXE)
	gcc $(FORKHEADERS) $(GLOBALHEADERS) $(GLOBARLFILES) $(FORKFILES) -o $(EXE2)
	gcc $(HTTPHEADERS) $(HTTPFILES) -o $(EXE3)

run_default_pre-thread:
	./$(EXE) -p 8080 -n 10 -w /home/julio/

run_default_pre-fork:
	./$(EXE2) -p 8080 -n 2 -w /home/julio/

run_default_client:
	./$(EXE3) -u /home/julio/

clean:
	rm $(EXE)
	rm $(EXE2)
	rm $(EXE3)