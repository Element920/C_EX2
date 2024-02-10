CC = gcc
FLAGS = -Wall -g

all: connections

connections: lib_my_mat.so my_graph.o my_Knapsack.o
	$(CC) $(FLAGS) -o connections my_graph.o my_Knapsack.o -L. -l_my_mat

lib_my_mat.so: my_mat.o
	$(CC) -shared -o lib_my_mat.so my_mat.o

my_mat.o: my_mat.h my_mat.c
	$(CC) $(FLAGS) -c my_mat.c

my_graph.o: my_graph.c my_mat.h
	$(CC) $(FLAGS) -c my_graph.c

my_Knapsack.o: my_Knapsack.c my_mat.h
	$(CC) $(FLAGS) -c my_Knapsack.c

clean:
	rm -f *.o *.a *.so connections

leakTest: all
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --error-exitcode=1 ./connections
