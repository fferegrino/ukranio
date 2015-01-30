run: compile
	./server.out
compile: compile-libs
	g++ server.cpp -o server.out SpaceShip.o GameObject.o -lX11 -lpthread
compile-libs:
	g++ -c GameObject.cpp 
	g++ -c SpaceShip.cpp 
clean:
	rm GameObject.o
	rm SpaceShip.o
	rm server.out
