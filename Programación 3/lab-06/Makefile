
# ajusta estas dos variable según tu distribución
ALEPH = /home/yurley/aleph/
CXX = clang++-3.6

CLANGPATH = /usr/bin

CXX = $(CLANGPATH)/clang++-3.6

WARN = -Wall -Wextra -Wcast-align -Wno-sign-compare -Wno-write-strings \
       -Wno-parentheses -Wno-invalid-source-encoding

FLAGS = -g -O0 -std=c++14 $(WARN)

INCLUDE = -I. -I $(ALEPH) 

LIBS = -L $(ALEPH) \
       -lAleph -lnana -lm -lgsl -lgslcblas -lgmp -lmpfr -lasprintf -lpthread -lc

all: test

clean:
	rm -f test

test: test.C stats.H 
	$(CXX) $(FLAGS) $(INCLUDE) $@.C -g -O0 -o $@ $(LIBS)


