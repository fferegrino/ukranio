#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <arpa/inet.h>
#include <cstring>
#include <time.h>
#include <ifaddrs.h>
#define PLEN 1000 

char * charTime();
char * getIpAddress();
void setData(char*);
char myIp[16];

struct Token {
	char ciclo[3];
	char ip[PLEN];
};

int main(int argc, char ** argv)
{
	
	char nextIp[16], myIp[16], tim[27];
	char mode = '\0';
	int puertoDestino = 0;
	int localPort = 0;
	if(argc < 4)
		exit(-1);
	
	strcpy(nextIp,argv[1]);	
	puertoDestino = atoi(argv[2]);
	mode = argv[3][0];
	
	PaqueteDatagrama  in = PaqueteDatagrama(0);
	SocketDatagrama server = SocketDatagrama(puertoDestino);
	
	printf("%s\n", myIp);
	Token t;
	/*
	char hys [] = "192.168.0.6 2015-02-03 21:40:29*192.168.0.5 2015-02-03 21:40:29*192.168.1.117 2015-02-03 21:40:29*";
	strcpy(t.ip, hys);
	printf("%s\n",t.ip);
	while(1)
	{
		setData(t.ip);
		printf("%s\n",t.ip);
		sleep(2);
	}
	*/
		
	
	//char hys [] = "192.168.0.6 2015-02-03 21:40:29*192.168.0.5 2015-02-03 21:40:29*192.168.1.117 2015-02-03 21:40:29*";
	//strcpy(t.ip, hys);
	if(mode == 'C')
	{
		sprintf(t.ciclo, "00");
		setData(t.ip);
		//printf("Data %s\n", t.ip);
		//sleep(1);
		in = PaqueteDatagrama((char*)&t, sizeof(t), nextIp, puertoDestino);
		server.envia(&in);
	}
	
	
	

	while(1)
	{
		PaqueteDatagrama  in2 = PaqueteDatagrama(sizeof(t));
		server.recibe(&in2);
		Token * data = (Token *) in2.obtieneDatos();

		if(mode == 'C')
		{
			int c = atoi(data->ciclo);
			c++;
			sprintf(data->ciclo, "%2d", c);
			printf("Ciclo %s: ", data->ciclo);
		}
		sleep(1);
		setData(data->ip);
		printf("%s\n", data->ip);
		PaqueteDatagrama out = PaqueteDatagrama((char *)data, sizeof(t),nextIp, puertoDestino);
		server.envia(&out);
	}
}

void setData(char * input)
{
		char  tim[80];
		strcpy(myIp,getIpAddress());
		strcpy(tim,charTime());
		int l, tl;
		char * nw = strstr(input,myIp);
		for(l = 0;myIp[l]; l++);
		for(tl = 0;tim[tl]; tl++);
		int offset = 0;
			
		if(nw != NULL)
		{
			char aux = nw[tl + l+2];
			strcpy (nw + l+1,tim);
			strcpy (nw + tl + l+1,"*");
			nw[tl + l+2] = aux;
		}
		else
		{
			for(offset = PLEN - 1; offset >= 0; offset--)
				if(input[offset] == '*')
				{
					offset++;
					break;
				}
			if(offset == -1) offset++; // Si es la primera IP
			strcpy (input + offset,myIp);
			strcpy (input + offset + l," ");
			strcpy (input + offset + l+1,tim);
			strcpy (input + offset + tl + l+1,"*");
		}
}

char * charTime(){
	
    time_t now;
    struct tm ts;
    char * buf = (char *)malloc(sizeof(char) * 80);
    //char buf[80];
    // Get current time
    time(&now);
    // Format time, "ddd yyyy-mm-dd hh:mm:ss zzz"
    ts = *localtime(&now);
    strftime(buf, sizeof(char) * 80, "%a %Y-%m-%d %H:%M:%S %Z", &ts);
    return buf; 

}

char * getIpAddress()
{
	char * ip = NULL;
	struct ifaddrs *iflist, *iface;
	if (getifaddrs(&iflist) < 0); // error
	unsigned long int localhostaddr = inet_addr("127.0.0.1");
	for (iface = iflist; iface && !ip; iface = iface->ifa_next)
	{
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
