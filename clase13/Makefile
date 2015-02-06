run: compile
	./cliente.out 192.168.1.100 7000 psetup.xpm 
	./cliente.out 192.168.1.100 7000 umax.jpg
	./cliente.out 192.168.1.100 7000 Linux.mp4 

compile: compile-libs
	g++ cliente.cpp -o cliente.out PaqueteDatagrama.o SocketDatagrama.o
compile-libs: 
	g++ -c PaqueteDatagrama.cpp
	g++ -c SocketDatagrama.cpp
clean:
	rm PaqueteDatagrama.o
	rm SocketDatagrama.o
	rm cliente.out
