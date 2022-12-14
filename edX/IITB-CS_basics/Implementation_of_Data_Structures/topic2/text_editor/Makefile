# For Linux or any machines with gcc compiler
CC = g++
#CFLAGS = -std=c++03 -Wall -pedantic
CFLAGS = -Wall -pedantic
BIN = ./bin

all: txtedit 

clean:
	rm *.o $(BIN)/*

OBJ= textEditor.o

txtedit: main.o $(OBJ) 
	$(CC) $(CFLAGS) -o txtedit main.o $(OBJ)
	mv txtedit $(BIN)
