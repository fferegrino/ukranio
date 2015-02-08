#ifndef __SOCKETDATAGRAMA_H__
#define __SOCKETDATAGRAMA_H__

#include "PaqueteDatagrama.h"
#include <netinet/in.h>

class SocketDatagrama{
	public:
		SocketDatagrama();
		SocketDatagrama(int);
		SocketDatagrama(int, char *);
		~SocketDatagrama();
		int recibe(PaqueteDatagrama *p);
		int envia(PaqueteDatagrama *p);
		char * obtieneIp();
		void setReusePort(bool);
		void setBroadcast(bool);
		void setReceiveTime(double seconds);
	private:
		struct sockaddr_in direccionLocal;
		struct sockaddr_in direccionForanea;
		int _s; //ID socket
};

#endif
