ALEPH = /home/yurley/aleph
CXX = clang++-3.6

OPTIMIZATION = -O0

WARN = -Wall -Wextra -Wcast-align -Wno-sign-compare -Wno-write-strings \
       -Wno-parentheses 

FLAGS = -DDEBUG -D_GLIBCXX__PTHREADS -g $(OPTIMIZATION) -std=c++14 $(WARN)

INCLUDE = -I. -I $(ALEPH) 

LIBS = -L $(ALEPH) \
       -lAleph -lnana -lc -lm -lgsl -lgslcblas -lgmp -lmpfr -lasprintf -lpthread

all: heap

heap: heap.C read-sum.C
	$(CXX) $(FLAGS) $(INCLUDE) $@.C -o $@  $(LIBS)


