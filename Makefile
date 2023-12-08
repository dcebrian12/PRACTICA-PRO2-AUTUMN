OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

G++ = g++

all: program.exe

Bicicleta.o: Bicicleta.cc Bicicleta.hh
	$(G++) -c Bicicleta.cc $(OPCIONS) 

Estacion.o: Estacion.cc Estacion.hh
	$(G++) -c Estacion.cc $(OPCIONS)

cjt_bicis.o: cjt_bicis.cc cjt_bicis.hh cjt_estaciones.hh Bicicleta.hh Estacion.hh
	$(G++) -c cjt_bicis.cc $(OPCIONS)

cjt_estaciones.o: cjt_estaciones.cc cjt_estaciones.hh 
	$(G++) -c cjt_estaciones.cc $(OPCIONS)

program.o: program.cc
	$(G++) -c program.cc $(OPCIONS)

program.exe: program.o Bicicleta.o Estacion.o cjt_bicis.o cjt_estaciones.o
	$(G++) -o program.exe program.o Bicicleta.o Estacion.o cjt_bicis.o cjt_estaciones.o $(OPCIONS)

practica.tar:
	tar -cvf practica.tar *.cc cjt_bicis.hh cjt_estaciones.hh Estacion.hh Bicicleta.hh Makefile

clean:
	rm -f *.o
	rm -f *.exe