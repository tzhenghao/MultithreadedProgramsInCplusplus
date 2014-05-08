# Zheng Hao Tan
# Date: May 8, 2014

#Enables C++11
PATH := /usr/um/gcc-4.7.0/bin:$(PATH)
LD_LIBRARY_PATH := /usr/um/gcc-4.7.0/lib64
LD_RUN_PATH := /usr/um/gcc-4.7.0/lib64

#Default Flags
FLAGS = -Wall -Wextra -pedantic -Wvla -std=c++11

# make release - will compile "all" with $(FLAGS) and the O3 flag
release: FLAGS += -O3
release: all

# make debug - will compile "all" with $(FLAGS) and the g flag
debug: FLAGS += -g
debug: all

gProf: FLAGS += -pg
gProf: all

all: base.o
	g++ $(FLAGS) base.o -o base

base.o: MST.h Graph.h TSP.h base.cpp
	g++ $(FLAGS) -c base.cpp

# make clean - remove .o files and the executable file.
# You can modify it to remove whatever.
clean:
	rm -f *.o base

submit:
	tar -czf submit.tar.gz *.cpp *.h Makefile test-*.txt
