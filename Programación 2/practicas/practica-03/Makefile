CXX := g++
CXXFLAGS := -Wall -o
OPTIONS := -std=c++11
INC := -I.
LIB := #-lm
SOURCES := mainPractica03.cpp
EXECUTABLE := mainPractica03

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CXX) $(OPTIONS) $^ $(CXXFLAGS) $@ $(INC) $(LIB)

clean:
	rm -fr *~ *.o $(EXECUTABLE)

