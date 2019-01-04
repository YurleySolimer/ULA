CXX := g++
CXXFLAGS := -o
INC := -I.
LIB :=
SOURCES := dynArrayMain.cpp dynArray.cpp
EXECUTABLE := dynArrayMain

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CXX) $^ $(CXXFLAGS) $@ $(INC) $(LIB)

clean:
	rm -fr *~ *.o $(EXECUTABLE)

