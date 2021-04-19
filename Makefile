CC=gcc
CFLAGS= -Wall -g

PROJECT= wargame

OBJ_FILES= main.o board.o modo_p1.o pieces.o restric.o modo_j0.o modo_j1.o

$(PROJECT): $(OBJ_FILES)
	gcc $(CFLAGS) -o $(PROJECT) $(OBJ_FILES) 

clean:
	rm -f *.o $(PROJECT)