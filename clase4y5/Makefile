runrect: pcomposicion
	./e1
pcomposicion: ejercicio1.cpp Rectangulo.o
	g++ ejercicio1.cpp Rectangulo.o Coordenada.o -o e1
Rectangulo.o: Rectangulo.cpp Coordenada.o
	g++ Rectangulo.cpp -c
Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c
clean:
	rm Rectangulo.o
	rm Coordenada.o
	rm e1
	rm Octoedro.o
