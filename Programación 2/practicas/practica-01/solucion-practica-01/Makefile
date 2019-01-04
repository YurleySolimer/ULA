CXX := g++
CXXFLAGS := -Wall -o
INC := -I.
LIB := -lm
SOURCES := point.cpp geometricFigure.cpp triangle.cpp rectangle.cpp mainPractica01.cpp
EXECUTABLE := mainPractica01

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CXX) $^ $(CXXFLAGS) $@ $(INC) $(LIB)

clean:
	rm -fr *~ *.o $(EXECUTABLE)

