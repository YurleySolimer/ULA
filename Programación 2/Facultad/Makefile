CC  =   g++
CFLAGS  = -g 
OTHERFLAGS = -c



Facultad:   mainFacultad.o Facultad.o Cadena.o
	   $(CC) $(CFLAGS)  mainFacultad.o Facultad.o Cadena.o -o Facultad 

mainFacultad.o: mainFacultad.cpp
		$(CC)  $(CFLAGS) $(OTHERFLAGS) mainFacultad.cpp

Facultad.o: Facultad.cpp
		$(CC)  $(CFLAGS) $(OTHERFLAGS) Facultad.cpp

Cadena.o: Cadena.cpp
		$(CC)  $(CFLAGS) $(OTHERFLAGS) Cadena.cpp

