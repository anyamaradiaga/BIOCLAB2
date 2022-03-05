#lab2 makefile 

CC = g++
SHELL = /bin/bash

all: pre_process.o vector_ops.o stats.o k_means.o

vector_ops.o: amaradiaga_vector_ops.cpp
	$(CC) -c $^

stats.o: amaradiaga_stats.cpp
	$(CC) -c $^

pre_process.o: amaradiaga_pre_processing.cpp
	$(CC) -c $^

k_means.o: amaradiaga_k_means.cpp
	$(CC) -o run $^

clean:
	rm *.o