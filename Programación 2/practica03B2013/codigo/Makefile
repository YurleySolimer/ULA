CXX := g++
CXXFLAGS := -Wall -o
INC := -I.
LIB := -lm
SOURCES := main.cpp Persona.cpp 
EXECUTABLE := persona

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CXX) $^ $(CXXFLAGS) $@ $(INC) $(LIB)

clean:
	rm -fr *~ *.o $(EXECUTABLE)

