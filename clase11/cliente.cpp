#include <sys/types.h>
#include <cstdlib>
#include <strings.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <algorithm>
#include <sys/wait.h>  
#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>
#include <ifaddrs.h>
#include <vector>
#include "SocketDatagrama.h"
#define TIEMPO_ESPERA 1
//#define DEBUG_IP

using namespace std;

void * procesoEmisor(void *);
void * procesoReceptor(void *);
void * procesoOrdenamiento( void *);
void sortAndPrint( int );
char* getIpAddress();

sem_t mx1;
sem_t mx2;

struct Ip {
	char  addr[16];
	int p;
	bool local;
};

vector<Ip> ips;

bool operator<( const Ip &ip1, const Ip &ip2)
{
    return ip1.p < ip2.p;
}


const int broadcastPort = 7200;
int main()
{
	
	SocketDatagrama sock = SocketDatagrama();
	sock.setBroadcast(true);
	
	sem_init(&mx1,0,0);
	sem_init(&mx2,0,1);
	pthread_t * hilos;
	hilos = (pthread_t*)malloc(3*sizeof(pthread_t));
	pthread_create(&hilos[0], NULL, procesoEmisor, (void *) &sock);
	pthread_create(&hilos[1], NULL, procesoReceptor,  (void *) &sock);
	pthread_create(&hilos[2], NULL, procesoOrdenamiento, NULL);
	
	for (int i=0; i<3; i++) 
		pthread_join(hilos[i], NULL);
	free(hilos);
}

void * procesoEmisor(void * auxiliar)
{
	SocketDatagrama * sock = (SocketDatagrama *)auxiliar;
	while(1)
	{
		sem_wait(&mx2);
		printf("Enviando...\n");
		PaqueteDatagrama envio = PaqueteDatagrama(NULL,0,"192.168.1.255", broadcastPort);
		sock->envia(&envio);
		sleep(TIEMPO_ESPERA);
		sem_post(&mx1);
	}
}


void * procesoReceptor(void * auxiliar)
{
	SocketDatagrama * sock = (SocketDatagrama *)auxiliar;
	PaqueteDatagrama recepcion = PaqueteDatagrama(0);
	while(1)
	{
		sock->recibe(&recepcion);
		Ip nueva;
		nueva.p = inet_addr(recepcion.obtieneDireccion()) >> 24;
		//	if(nueva.p != 255)
		{
			nueva.local = false;
			strcpy (nueva.addr,recepcion.obtieneDireccion());	
			//printf("%s\n", recepcion.obtieneDireccion());
			if(!binary_search(ips.begin(),ips.end(), nueva))
			{
				ips.push_back(nueva);
				sort(ips.begin(), ips.end());
			}
			else
				printf("%s ya esta dentro de la lista de ip\n", nueva.addr);
		}
	}
}

void sortAndPrint(int x){
	sort(ips.begin(), ips.end());
	for(int i = 0; i < ips.size(); i++)
	{
		printf("IP: %s", ips[i].addr);
		ips[i].p == x ? printf("*\n") : printf("\n");
	}
}

void * procesoOrdenamiento( void *)
{
	char * self;
	self = getIpAddress();
	Ip selfIp;
	selfIp.local = true;
	strcpy (selfIp.addr,self);	
	selfIp.p = inet_addr(self) >> 24;
	while(1)
	{
		sem_wait(&mx1)	;
		printf("Lista de IP:\n");
		//ips.push_back(selfIp);
		sortAndPrint(selfIp.p);
		ips.clear();
		sleep(5);
		sem_post(&mx2);
	}
	free(self);
}

char * getIpAddress()
{
	char * ip = NULL;
	struct ifaddrs *iflist, *iface;
	if (getifaddrs(&iflist) < 0); // error
	unsigned long int localhostaddr = inet_addr("127.0.0.1");
	for (iface = iflist; iface && !ip; iface = iface->ifa_next)
	{
		//printf("Interface name: %s\n", iface->ifa_name);
		#ifdef DEBUG_IP
		int family = iface->ifa_addr->sa_family;
		printf("%-8s %s (%d)\n",
                      iface->ifa_name,
                      (family == AF_PACKET) ? "AF_PACKET" :
                      (family == AF_INET) ? "AF_INET" :
                      (family == AF_INET6) ? "AF_INET6" : "???",
                      family);
		#endif
		if(iface->ifa_addr->sa_family == AF_INET &&  localhostaddr != ((struct sockaddr_in *)iface->ifa_addr)->sin_addr.s_addr)
		{ 
			ip = inet_ntoa(((struct sockaddr_in *)iface->ifa_addr)->sin_addr);
		}
	}
	freeifaddrs(iflist);
	return ip;
}
