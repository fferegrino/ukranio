run: a.out
	./a.out 2
	./a.out 5
	./a.out 10
a.out: PoligonoIrregular.o Coordenada.o
	g++ Ejercicio1y2.cpp Coordenada.o PoligonoIrregular.o
PoligonoIrregular.o: Coordenada.o
	g++ PoligonoIrregular.cpp -c
Coordenada.o:
	g++ Coordenada.cpp -c
clean:
	rm Coordenada.o
	rm PoligonoIrregular.o
	rm a.out
