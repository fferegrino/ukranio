#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>  
#include <cstdlib>
#define TIEMPO_ESPERA 1
#define MAX_NUMERO 10000000;

int puerto = 7201;
int broadcastPort = 7300;

int main(void)
{
	struct sockaddr_in broadcast_addr, local_addr, server_addr;
	unsigned server_addr_len=sizeof(server_addr);
	int s, num[2], res,i;
   	char *ipServidor;
	char ipDestino[16];
	
	struct timeval tiempoEspera;
	tiempoEspera.tv_sec = 2ll;
	tiempoEspera.tv_usec = 20000ll;

	int yes = 1;
	s = socket(AF_INET, SOCK_DGRAM, 0);
	//setsockopt(s, SOL_SOCKET, SO_BROADCAST, &yes,sizeof(int));
	setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&tiempoEspera,sizeof(tiempoEspera));
	
	// Servidor:
	bzero((char *)&broadcast_addr, sizeof(broadcast_addr));
	broadcast_addr.sin_family = AF_INET;
	broadcast_addr.sin_addr.s_addr = inet_addr("192.168.1.255");
	broadcast_addr.sin_port = htons(broadcastPort);

	// Local:
	bzero((char *)&local_addr, sizeof(local_addr));
	local_addr.sin_family = AF_INET;
	local_addr.sin_addr.s_addr = INADDR_ANY;
	local_addr.sin_port = htons(0);
   

	bind(s, (struct sockaddr *)&local_addr,sizeof(local_addr));
	/*
	char opt = 'y';
	while(opt == 'y')
	{
	*/
		// Padre:
		printf("Numero A: \n");
		scanf("%d", &(num[0]));
		printf("Numero B: \n");
		scanf("%d", &(num[1]));
		int addr = 100;
		while(addr < 255)
		{
			bzero((char *)&broadcast_addr, sizeof(broadcast_addr));
			broadcast_addr.sin_family = AF_INET;
			char ipp[16] = "192.168.1.";
			char n[3];
			//std::itoa(addr, n, 10);
			sprintf(n,"%d", addr);
			strcat(ipp, n);
			broadcast_addr.sin_addr.s_addr = inet_addr(ipp);
			broadcast_addr.sin_port = htons(broadcastPort);
			printf("Conectando a: %s\n", ipp);
			res = 0;
			sendto(s, (char *)num, 2 * sizeof(int), 0, (struct sockaddr *) &broadcast_addr, sizeof(broadcast_addr));
			int tout = recvfrom(s, (char *)&res, sizeof(int), 0, (sockaddr  *)&server_addr, &server_addr_len);

			if(tout != -1)
			{
				ipServidor = inet_ntoa(server_addr.sin_addr);
				printf("%s:%d resultado: %d\n",ipServidor, server_addr.sin_port, res);
			}
			else{
					printf("Timeout\n");
			}
			addr+=2;
		}
	
    
   
}


