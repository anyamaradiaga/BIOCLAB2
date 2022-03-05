#Name: Anya Maradiaga
#Description: Makefile for lab2

CC = g++

vector_ops.o: amaradiaga_vector_ops.hpp amaradiaga_vector_ops.cpp
g++ -c vector_ops $^

stats_lab1.o: amaradiga_stats.cpp amaradiaga_stats.hpp amaradiaga_stats_test.cpp
g++ -c stats_lab1 $^

preprocess.o: amaradiaga_pre_processing.cpp amaradiaga_pre_processing.hpp amaradiaga_stats.cpp amaradiaga_stats.hpp amaradiaga_vector_ops.cpp amaradiaga_vector_ops.hpp
g++ -c preprocess $^

cluster.o: amaradiaga_k_means.cpp amaradiaga_k_means.hpp amaradiaga_stats.cpp amaradiaga_stats.hpp amaradiaga_pre_processing.cpp amaradiaga_pre_processing.hpp amaradiaga_vector_ops.cpp amaradiaga_vector_ops.hpp
g++ -c cluster $^

all: vector_ops.o stats_lab1.o preprocess.o cluster.o

clean:
rm -f *.o 
rm -f *.gch
rm -f all 
			


