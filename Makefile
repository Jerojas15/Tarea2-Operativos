HEADERS = webServer.h
FILES = webServer.c
LIBRARYS = -pthread
EXE = eje

all: 
	gcc $(LIBRARYS) $(HEADERS) $(FILES) -o $(EXE)

run_default_pre-thread:
	./$(EXE) -p 8888 -t 10

run_default_pre-fork:
	./$(EXE) -p 8888 -f 10	