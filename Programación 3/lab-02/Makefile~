ALEPH = /home/yurley/aleph
CXX = clang++-3.5

WARN = -Wall -Wextra -Wcast-align -Wno-sign-compare -Wno-write-strings \
       -Wno-parentheses 

FLAGS = -DDEBUG -D_GLIBCXX__PTHREADS -g -O0 -std=c++14 $(WARN)

OPT = -DNDEBUG -D_GLIBCXX__PTHREADS -g -O3 -std=c++14 $(WARN)

INCLUDE = -I. -I $(ALEPH) 

LIBS = -L $(ALEPH) -lAleph -lnana -lc -lm -lgsl -lgslcblas -lgmp -lmpfr -lasprintf -lpthread

all: qs rand 

clean:
	rm -f qs rand grader qs-op

qs: qs.C q.H	
	$(CXX) $(FLAGS) $(INCLUDE) $@.C -o $@  $(LIBS)

rand: rand.C	
	$(CXX) $(FLAGS) $(INCLUDE) $@.C -o $@  $(LIBS)
