ALEPH = /home/yurley/aleph/
CXX = clang++-3.5

OPTIMIZATION = -O0

WARN = -Wall -Wextra -Wcast-align -Wno-sign-compare -Wno-write-strings \
      -Wno-parentheses 

FLAGS = -DDEBUG -D_GLIBCXX__PTHREADS -g $(OPTIMIZATION) -std=c++14 $(WARN)

INCLUDE = -I. -I $(ALEPH) 

LIBS = -L $(ALEPH) \
       -lAleph -lnana -lc -lm -lgsl -lgslcblas -lgmp -lmpfr -lasprintf -lpthread


main: dictnode.H main.cpp
	$(CXX) $(FLAGS) $(INCLUDE) $@.cpp -o $@  $(LIBS)

