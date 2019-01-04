CXX = clang++-3.8

WARN = -Wall -Wextra -Wcast-align -Wno-sign-compare -Wno-write-strings \
       -Wno-parentheses

FLAGS = -O0 -g -std=c++14 $(WARN)

INCLUDE = -I. -I $(ALEPH) 

LIBS = -L $(ALEPH) -lAleph -lgsl -lgslcblas

test:
	$(CXX) $(FLAGS) $(INCLUDE) operaciones.C -o operaciones $(LIBS)

clean:
	$(RM) *~ *.o


