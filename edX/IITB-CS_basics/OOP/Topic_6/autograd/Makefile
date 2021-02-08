#make autograd
CC= g++
CFLAGS = -std=c++03 -Wall -pedantic
BIN= ./bin
all: autograd_univariate

clean:
	rm *.o $(BIN)/*

OBJ= ConstPoly.o graph.o Node.o Polynomial.o

autograd_univariate: main.o $(OBJ) 
	$(CC) $(CFLAGS) -o autograd main.o $(OBJ) -lm
	mv autograd $(BIN)
