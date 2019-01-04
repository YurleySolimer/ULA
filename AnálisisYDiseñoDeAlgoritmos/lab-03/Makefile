
ALEPH = /home/yurley/aleph

CLANGPATH=/usr/bin/
CXX = clang++-3.6 -std=c++14 

OPT=-D_GLIBCXX__PTHREADS -pthread -Ofast -std=c++14 -stdlib=libstdc++ $(WARN) -D__extern_always_inline="extern __always_inline" 

WARN = -Wall -Wextra -Wcast-align -Wno-sign-compare -Wno-write-strings \
       -Wno-parentheses 

FLAGS = -DDEBUG -D_GLIBCXX__PTHREADS -g -O0 -std=c++14 $(WARN)

INCLUDE = -I. -I $(ALEPH) 

LIBS = -L $(ALEPH) -lAleph -lc -lm -lgsl -lgslcblas -lgmp -lmpfr -lasprintf

all: min-dist fast-min_dist 

clean:
	rm -f min-dist fast-min_dist 

min-dist: min-dist.C min-dist.H defs.H
	$(CXX) $(FLAGS) $(INCLUDE) $@.C -o $@ $(LIBS)

fast-min_dist: min-dist.C min-dist.H
	$(CXX) $(OPT) $(INCLUDE) min-dist.C -o fast-min_dist $(LIBS)
