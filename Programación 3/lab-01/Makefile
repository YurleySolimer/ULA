ALEPH = /home/yurley/aleph

CXX = clang++-3.5

OPT = -O0

WARN = -Wall -Wextra -Wcast-align -Wno-sign-compare -Wno-write-strings \
       -Wno-parentheses 

FLAGS = -DDEBUG -D_GLIBCXX__PTHREADS -g $(OPTIMIZATION) -std=c++11 $(WARN)

INCLUDE = -I. -I $(ALEPH) 

LIBS = -L $(ALEPH) -lAleph -lc -lm -lgsl -lgslcblas -lgmp -lmpfr -lasprintf -lpthread

all: test

clean: 
	rm -f test

test: test.C test.H
	$(CXX) $(FLAGS) $(INCLUDE) $@.C -o $@ $(LIBS)
