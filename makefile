
CC = gcc
AR = ar
CFLAGS = -Wall -g
AFLAGS = rcs

.PHONY: all clean

all: my_graph

my_graph: main.o libmymath.a
	$(CC) $(CFLAGS) main.o libmymath.a -o my_graph

libmymath.a: my_mat.o
	$(AR) $(AFLAGS) libmymath.a my_mat.o

main.o: main.c my_mat.h
	$(CC) $(CFLAGS) -c main.c

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c my_mat.c

clean:
	rm -f *.o *.a my_graph