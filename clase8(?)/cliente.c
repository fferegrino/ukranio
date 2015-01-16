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
#define TIEMPO_ESPERA 1
#define MAX_NUMERO 10000000;

int puerto = 7200;
int broadcastPort = 7200;

int main(void)
{
	struct sockaddr_in broadcast_addr, local_addr, server_addr;
	unsigned server_addr_len=sizeof(server_addr);
	int s, num[2], res,i;
   	char *ipServidor;
	char ipDestino[16];

	int yes = 1;
	s = socket(AF_INET, SOCK_DGRAM, 0);
	setsockopt(s, SOL_SOCKET, SO_BROADCAST, &yes,sizeof(int));
	
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

	pid_t hijo_id = fork();

	int waitForIt;

	if (hijo_id == 0)
	{
		// Hijo:
		while(1)
		{
			recvfrom(s, (char *)&res, sizeof(int), 0, (sockaddr  *)&server_addr, &server_addr_len);
			ipServidor = inet_ntoa(server_addr.sin_addr);
			printf("%s:%d resultado: %d\n",ipServidor, server_addr.sin_port, res);
			//sleep(TIEMPO_ESPERA);
		}	
		return 0;
	}
	else if (hijo_id > 0)
	{
		// Padre:
		printf("Numero A: \n");
		scanf("%d", &(num[0]));
		printf("Numero B: \n");
		scanf("%d", &(num[1]));
		char opt = 'y';
		while(opt == 'y')
		{
			sendto(s, (char *)num, 2 * sizeof(int), 0, (struct sockaddr *) &broadcast_addr, sizeof(broadcast_addr));
			sleep(TIEMPO_ESPERA);
			num[0] = (num[0]+1) % MAX_NUMERO;
			num[1] = (num[1]+1) % MAX_NUMERO;
		}	
		wait(&waitForIt);
	}
	else
	{
		// OMG ERROR!!!!1!!
	}
    
   
}


