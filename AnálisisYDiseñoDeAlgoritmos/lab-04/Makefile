
ALEPH = /home/yurley/aleph

CLANGPATH=/usr/bin/
CXX = clang++-3.6 -std=c++14 

WARN = -Wall -Wextra -Wcast-align -Wno-sign-compare -Wno-write-strings \
       -Wno-parentheses 

FLAGS = -DDEBUG -D_GLIBCXX__PTHREADS -g -O0 -std=c++14 $(WARN)

OPT = -DNDEBUG -D_GLIBCXX__PTHREADS -Ofast -std=c++14 $(WARN)

INCLUDE = -I. -I $(ALEPH) 

LIBS = -L $(ALEPH) -lAleph -lc -lm -lgsl -lgslcblas -lgmp -lmpfr -lasprintf -lpthread

all: rand-gen solver solver-op net.o 

clean: 
	rm -f rand-gen solver solver-op net.o

net.o: net.H net.C
	$(CXX) -c $(FLAGS) $(INCLUDE) net.C -o net.o

rand-gen: rand-gen.C net.o
	$(CXX) $(FLAGS) $(INCLUDE) $@.C -o $@ net.o $(LIBS)

solver: net.o solver.H solver.C 
	$(CXX) $(FLAGS) $(INCLUDE) $@.C -o $@ net.o $(LIBS)

solver-op: net.o solver.C 
	$(CXX) $(OPT) $(INCLUDE) solver.C -o solver-op net.o $(LIBS)

