run: a.out
	./a.out
a.out: Rectangulo.o
	g++ ejercicio4.cpp Coordenada.o Rectangulo.o
Rectangulo.o: Coordenada.o
	g++ Rectangulo.cpp -c
Coordenada.o:
	g++ Coordenada.cpp -c
clean:
	rm Coordenada.o
	rm Rectangulo.o
	rm ./a.out


