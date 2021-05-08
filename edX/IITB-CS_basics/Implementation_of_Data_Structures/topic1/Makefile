CC=g++
CFLAGS= -std=c++03 -Wall -pedantic
BIN = ./bin

all: gpa01

clean:
	rm *.o $(BIN)/*

OBJ= gpa01.o

gpa01: main.o $(OBJ)
	$(CC) $(CFLAGS) -o gpa01 main.o $(OBJ) -lm
	mv gpa01 $(BIN)
