#Name: Anya Maradiaga
#Date: April 13, 2022
#Description: makefile for mini project 1

CC = g++ -c
SHELL= /bin/bash
CFLAGS = -fPIC -g

amaradiaga_stats.o: amaradiaga_stats.cpp amaradiaga_stats.hpp
	$(CC) $(CFLAGS) $^ -lm

libstats.so: amaradiaga_stats.o 
	$(CC) -shared $^ -o $@

all: libstats.o

clean:
	rm -f *.o
	rm -f *.gch