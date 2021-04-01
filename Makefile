CC=gcc
CFLAGS= -Wall -pedantic -g

PROJECT= main

OBJ_FILES= $(PROJECT).o board.o modo_p1.o pieces.o

$(PROJECT): $(OBJ_FILES)
	gcc $(CFLAGS) -o $(PROJECT) $(OBJ_FILES) 

clean:
	rm -f *.o $(PROJECT)