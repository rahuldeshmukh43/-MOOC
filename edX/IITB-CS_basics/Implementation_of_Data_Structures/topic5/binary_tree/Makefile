CC = g++
CFLAGS = -g -Wall -pedantic

all: binary_tree

clean:
	rm -f ./*.o binary_tree_1_main

OBJ = binary_tree_1.o

binary_tree: 
	$(CC) $(CFLAGS) -o $(OBJ) -c binary_tree_1.cpp
	$(CC) $(CFLAGS) -o binary_tree_1_main.o -c binary_tree_1_main.cpp 
	$(CC) $(CFLAGS) -o binary_tree_1_main ./binary_tree_1*.o -lm #binary_tree_1_main.cpp $(OBJ)
