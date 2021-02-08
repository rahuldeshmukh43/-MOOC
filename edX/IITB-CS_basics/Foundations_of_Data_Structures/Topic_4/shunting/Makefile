#make shunting 
CC= g++
CFLAGS = -std=c++03 -Wall -pedantic
BIN= ./bin
all: shunting 

clean:
	rm *.o $(BIN)/*

OBJ= shunting_help.o Stack.o
shunting: main.o $(OBJ) 
	$(CC) $(CFLAGS) -o shunting main.o $(OBJ)
	mv shunting $(BIN)
