ALEPH = /home/yurley/aleph
CXX = clang++-3.5

OPTIMIZATION = -O0

WARN = -Wall -Wextra -Wcast-align -Wno-sign-compare -Wno-write-strings \
       -Wno-parentheses 

FLAGS = -DDEBUG -D_GLIBCXX__PTHREADS -g $(OPTIMIZATION) -std=c++11 $(WARN)

INCLUDE = -I. -I $(ALEPH) 

LIBS = -L $(ALEPH) \
       -lAleph -lnana -lc -lm -lgsl -lgslcblas -lgmp -lmpfr -lasprintf -lpthread

all: sudoku-solve sudoku-tests

sudoku-solve: sudoku-solve.C sudoku.H sudoku.C
	$(CXX) $(FLAGS) $(INCLUDE) $@.C -o $@ $(LIBS)

sudoku-tests: sudoku-tests.C sudoku.H sudoku.C
	$(CXX) $(FLAGS) $(INCLUDE) $@.C -o $@ $(LIBS)
