run: compile
	./server.out
#	./cliente.out
test: 
	g++ test.cpp -o _test.out 
	./_test.out
compile: compile-libs
	g++ server.cpp -o server.out SpaceShip.o GameObject.o Asteroid.o PaqueteDatagrama.o SocketDatagrama.o -std=c++11
	g++ cliente.cpp -o cliente.out SpaceShip.o GameObject.o PaqueteDatagrama.o SocketDatagrama.o -lX11
compile-libs:
	g++ -c GameObject.cpp 
	g++ -c SpaceShip.cpp 
	g++ -c Asteroid.cpp -std=c++11
	g++ -c PaqueteDatagrama.cpp
	g++ -c SocketDatagrama.cpp
	clear
clean:
	rm GameObject.o
	rm SpaceShip.o
	rm Asteroid.o
	rm PaqueteDatagrama.o
	rm SocketDatagrama.o
	rm server.out
	clear

