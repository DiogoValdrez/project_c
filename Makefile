CC=gcc
CFLAGS= -Wall -std=c11 -O3

PROJECT= wargame

OBJ_FILES= main.o board.o modo_p1.o pieces.o restric.o modo_j0.o modo_j1.o modo_p2.o modo_d1.o modo_j2.o modo_d2.o modo_d3.o

$(PROJECT): $(OBJ_FILES)
	gcc $(CFLAGS) -o $(PROJECT) $(OBJ_FILES) 

clean:
	rm -f *.o $(PROJECT)
