CXX = clang++-3.6 -std=c++14 

WARN = -Wall -Wextra -Wcast-align -Wno-sign-compare -Wno-write-strings -Wno-parentheses -Wno-invalid-source-encoding

FLAGS = -D_GLIBCXX__PTHREADS $(WARN)

FLAGS_DEBUG = -O0 -g -DDEBUG $(FLAGS)

FLAGS_RELEASE = -Ofast $(FLAGS)

ALEPH = /home/yurley/aleph

INCLUDE = -I $(ALEPH)

LIBS = -L $(ALEPH) -lAleph -lgsl -lgslcblas

default: all

all: ex1 ex2 ex3 ex4 ex5 ex6

ex1: ex1.C
	$(CXX) $(FLAGS_DEBUG) $(INCLUDE) $@.C -o $@ $(LIBS)

ex1-op: ex1.C
	$(CXX) $(FLAGS_RELEASE) $(INCLUDE) ex1.C -o $@ $(LIBS)

ex2: ex2.C
	$(CXX) $(FLAGS_DEBUG) $(INCLUDE) $@.C -o $@ $(LIBS)

ex2-op: ex2.C
	$(CXX) $(FLAGS_RELEASE) $(INCLUDE) ex2.C -o $@ $(LIBS)

ex3: ex3.C
	$(CXX) $(FLAGS_DEBUG) $(INCLUDE) $@.C -o $@ $(LIBS)

ex3-op: ex3.C
	$(CXX) $(FLAGS_RELEASE) $(INCLUDE) ex3.C -o $@ $(LIBS)

ex4: ex4.C
	$(CXX) $(FLAGS_DEBUG) $(INCLUDE) $@.C -o $@ $(LIBS)

ex4-op: ex4.C
	$(CXX) $(FLAGS_RELEASE) $(INCLUDE) ex4.C -o $@ $(LIBS)

ex5: ex5.C
	$(CXX) $(FLAGS_DEBUG) $(INCLUDE) $@.C -o $@ $(LIBS)

ex5-op: ex5.C
	$(CXX) $(FLAGS_RELEASE) $(INCLUDE) ex5.C -o $@ $(LIBS)

ex6: ex6.C
	$(CXX) $(FLAGS_DEBUG) $(INCLUDE) $@.C -o $@ $(LIBS)

ex6-op: ex6.C
	$(CXX) $(FLAGS_RELEASE) $(INCLUDE) ex6.C -o $@ $(LIBS)

clean:
	$(RM) *~ ex1 ex1-op ex2 ex2-op ex3 ex3-op ex4 ex4-op ex5 ex5-op ex6 ex6-op
