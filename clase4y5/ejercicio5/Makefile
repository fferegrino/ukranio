run: a.out
	./a.out
a.out:	Octoedro.o
	g++ ejercicio5.cpp Octoedro.o Rectangulo.o Coordenada.o
Octoedro.o: Rectangulo.o
	g++ Octoedro.cpp -c
Rectangulo.o: Coordenada.o
	g++ Rectangulo.cpp -c
Coordenada.o:
	g++ Coordenada.cpp -c
clean:
	rm Coordenada.o
	rm Rectangulo.o
	rm Octoedro.o
	rm a.out
