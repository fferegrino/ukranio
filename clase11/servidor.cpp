#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <cstdlib>
#include <cstdio>

int main()
{
	SocketDatagrama server = SocketDatagrama(7200);
	server.setBroadcast(true);
	PaqueteDatagrama in = PaqueteDatagrama(0);
	printf("xD\n");
	while(1)
	{
		server.recibe(&in);
		printf("Recibe de %s:%d\n", in.obtieneDireccion(), in.obtienePuerto());
		PaqueteDatagrama out = PaqueteDatagrama(NULL,0,in.obtieneDireccion(), in.obtienePuerto());
		server.envia(&out);
	}
}

