# coloca aqui tu camino hacia aleph
ALEPH = /home/yurley/aleph

# Coloca aqui tu camino hacia clang
CXX = clang++-3.6 -std=c++14 

# De aqui en adelante se te aconseja no jurungar!

OPTIMIZATION = -O0

WARN = -Wall -Wextra -Wcast-align -Wno-sign-compare -Wno-write-strings \
       -Wno-parentheses 

FLAGS = -DDEBUG -D_GLIBCXX__PTHREADS -g $(OPTIMIZATION) -std=c++14 $(WARN)

INCLUDE = -I. -I $(ALEPH) 

LIBS = -L $(ALEPH) \
       -lAleph -lnana -lc -lm -lgsl -lgslcblas -lgmp -lmpfr -lasprintf -lpthread

all: rand-paths to-dot gen-net

clean:
	rm -f rand-paths to-dot gen-net to-do

rand-paths: rand-paths.C net.H find.H
	$(CXX) $(FLAGS) $(INCLUDE) $@.C -o $@  $(LIBS)

gen-net: gen-net.C gen-net.H net.H find.H
	$(CXX) $(FLAGS) $(INCLUDE) $@.C -o $@  $(LIBS)

to-dot: to-dot.C net.H find.H
	$(CXX) $(FLAGS) $(INCLUDE) $@.C -o $@  $(LIBS)
