CC  =   g++
CFLAGS  = -g 
OTHERFLAGS = -c



carro:   mainCarro.o Carro.o Cadena.o
	   $(CC) $(CFLAGS)  mainCarro.o Carro.o Cadena.o -o carro 

mainCarro.o: mainCarro.cpp
		$(CC)  $(CFLAGS) $(OTHERFLAGS) mainCarro.cpp

Carro.o: Carro.cpp
		$(CC)  $(CFLAGS) $(OTHERFLAGS) Carro.cpp

Cadena.o: Cadena.cpp
		$(CC)  $(CFLAGS) $(OTHERFLAGS) Cadena.cpp

