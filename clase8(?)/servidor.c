#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>
#include <arpa/inet.h>

int puerto = 7200;

int main(void)
{
	int num[2];
	char*ip;
	int s, res, yes = 1;
	struct sockaddr_in server_addr, client_addr;
	unsigned int client_addr_len = sizeof(client_addr);
   
	s = socket(AF_INET, SOCK_DGRAM, 0);
	setsockopt(s, SOL_SOCKET, SO_BROADCAST, &yes,sizeof(int));
	setsockopt(s, SOL_SOCKET, SO_REUSEPORT, &yes,sizeof(int));
	int port = 0;
	
	bzero((char *)&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(puerto);
   
   
   	if(bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr)) >= 0)
	{
		while(1) 
		{
			printf("Esperando conexión\n");
			recvfrom(s, (char *) num, 2*sizeof(int), 0, (struct sockaddr *)&client_addr, &client_addr_len);
			res = num[0] + num[1];
			printf("Conexion aceptada de %s, numeros: %d y %d\n",inet_ntoa(client_addr.sin_addr), num[0], num[1]);
			sendto(s, (char *)&res, sizeof(int), 0, (struct sockaddr *)&client_addr, client_addr_len);
		}
	}
}	
