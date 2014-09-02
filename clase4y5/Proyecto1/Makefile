run: a.out
	./a.out
a.out: Paralelepipedo.o
	g++ Main.cpp Paralelepipedo.o Paralelogramo.o Vector.o
Paralelepipedo.o: Paralelogramo.o
	g++ Paralelepipedo.cpp -c
Paralelogramo.o: Vector.o
	g++ Paralelogramo.cpp -c
Vector.o:
	g++ Vector.cpp -c
clean:
	rm Vector.o
	rm Paralelogramo.o
	rm Paralelepipedo.o
	rm ./a.out
