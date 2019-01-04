GPP := g++
CFLAGS := -c -o
INC := -Iinclude

all: fibonacci

fibonacci.o: fibonacci.cpp
	$(GPP) $< $(CFLAGS) $@ $(INC)

fibonacci: fibonacci.o
	$(GPP) $< -o $@

clean:
	rm *~ *.o fibonacci
