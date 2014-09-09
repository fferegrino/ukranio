run: prog5 ej3 ej2
ej2:
	g++ Ejercicio2.cpp -o ej2.out
ej3:
	g++ Ejercicio3.cpp -o normal.out
	g++ Ejercicio3.cpp -DRESERVE -o reserve.out
prog5: programa5
programa5: programa5.cpp Fecha.o
	g++ programa5.cpp Fecha.o -o prog5
Fecha.o: Fecha.cpp Fecha.h
	g++ Fecha.cpp -c
clean:
	rm Fecha.o
	rm ./normal.out
	rm ./reserve.out
	rm ./ej2.out
