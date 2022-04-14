#Name: Anya Maradiaga
#Date: April 13, 2022
#Description: makefile for mini project 1

CC = g++
SHELL = /bin/bash
CFLAGS = -fPIC -g #compiler flags
LDFLAGS = -lm -lstats

#directory path for library
LIBDIR = /home/maradia/BIOCLAB2/lab1a

#where header file is
INCDIR = /home/maradia/BIOCLAB2/lab1a

libstats.so: 
	cd /home/maradia/BIOCLAB2/lab1a && make libstats.so

airspeed: /home/maradia/BIOCLAB2/miniproject1/amaradiaga_miniproject1.cpp
	$(CC) $(CFLAGS) -I$(INCDIR) -o $@ $< -Wl,-rpath=$(LIBDIR) -L$(LIBDIR) $(LDFLAGS)
	./airspeed swallowspeed.dat

clean:
	rm -f *.o 
	rm -f *.gch
	rm -f airspeed 
			


