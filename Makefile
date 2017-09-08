THREADHEADERS = threadWebServer.h socket.h
THREADFILES = threadWebServer.c socket.c
GLOBALHEADERS = httpRequestHandler.h requestHandler.h
GLOBARLFILES = httpRequestHandler.c requestHandler.c
FORKHEADERS = forkWebServer.c socket.c
FORKFILES = forkWebServer.h socket.h
LIBRARYS = -pthread
EXE = prethread-webserver
EXE2 = preforked-webserver

all: 
	gcc $(LIBRARYS) $(THREADHEADERS) $(GLOBALHEADERS) $(GLOBARLFILES) $(THREADFILES) -o $(EXE)
	gcc $(FORKHEADERS) $(GLOBALHEADERS) $(GLOBARLFILES) $(FORKFILES) -o $(EXE2)

run_default_pre-thread:
	./$(EXE) -p 2022 -n 10

run_default_pre-fork:
	./$(EXE2) -p 2022 -n 2	

clean:
	rm $(EXE)
	rm $(EXE2)