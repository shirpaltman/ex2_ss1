
CC = gcc
AR = ar
CFLAGS = -Wall -g
AFLAGS = rcs

.PHONY: all clean

all: my_graph 

my_graph: my_graph.o libmymath.a
	$(CC) $(CFLAGS) my_graph.o libmymath.a -o my_graph

libmymath.a: my_mat.o
	$(AR) $(AFLAGS) libmymath.a my_mat.o

my_graph.o: my_graph.c my_mat.h
	$(CC) $(CFLAGS) -c my_graph.c

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c my_mat.c

clean:
	rm -f *.o *.a my_graph