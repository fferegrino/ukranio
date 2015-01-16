run: compile	
compile: PaqueteDatagrama.o SocketDatagrama.o
	g++ cliente.cpp PaqueteDatagrama.o SocketDatagrama.o -o c
	g++ servidor.cpp PaqueteDatagrama.o SocketDatagrama.o -o s
PaqueteDatagrama.o:
	g++ -c PaqueteDatagrama.cpp
SocketDatagrama.o:
	g++ -c SocketDatagrama.cpp
clean:
	rm PaqueteDatagrama.o
	rm SocketDatagrama.o
	rm c
	rm s
