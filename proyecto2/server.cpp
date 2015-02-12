#pragma GCC diagnostic ignored "-Wwrite-strings"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include "SpaceShip.h"
#include "Asteroid.h"
#include "AsteroidFactory.h"
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include "GameCommon.h"



char clientIp[16];
int clientPort;

int main()
{
	initAsteroidFactory();
	
	SocketDatagrama skt = SocketDatagrama(C_SERVER_PORT);
	PaqueteDatagrama in = PaqueteDatagrama(sizeof(ClientRequest));
	int x = G_WINDOW_WIDTH / 2;
	ClientRequest * clientRequest;
	PaqueteDatagrama * out = NULL;
	SpaceShip * spaceShip = NULL;
	Asteroid ** asteroids = NULL;
	int asteroidC = 0;
	ServerAnswer sa;
	int request = 0;
	int requestOpt = -1;
	int angle = 0;
	int xast = 0;
	do {
		skt.recibe(&in);
		clientRequest  = (ClientRequest *)in.obtieneDatos();
		request = clientRequest->request;
		requestOpt = clientRequest->requestOpt;
		strcpy(clientIp, in.obtieneDireccion());
		clientPort = in.obtienePuerto();
		switch(request)
		{
			case R_STARTGAME:
				free(asteroids);
				free(spaceShip);
				sa.answer = R_STARTGAME;
				sa.count = 0;
				out = new PaqueteDatagrama((char*)&sa, sizeof(sa), clientIp, clientPort);
				spaceShip =  new SpaceShip(G_WINDOW_WIDTH  / 2 ,G_WINDOW_HEIGHT / 2);
				asteroidC =  asteroidCount();
				asteroids = (Asteroid **)malloc(sizeof(Asteroid *) * asteroidC);
				for(int ii = 0; ii < asteroidC; ii++)
				{
					int nodeC = nodeCount();
					asteroids[ii] = new Asteroid(nodeC, 0 + ii * nextRadio(),0, 40 + ii * nextRadio(), 19);
					for(int iii = 0; iii < nodeC; iii++)	
						asteroids[ii]->addNextRadio(nextRadio());
				}
				
				break;
			case R_SPACESHIP:
				sa.answer = R_SPACESHIP;
				sa.count = spaceShip->getPointCount();
				memcpy(sa.points, spaceShip->getPoints(), sa.count*sizeof(XPoint));
				out = new PaqueteDatagrama((char*)&sa, sizeof(sa), clientIp, clientPort);
				break;
			case R_ASTEROID_COUNT:
				sa.answer = R_ASTEROID_COUNT;
				sa.count = asteroidC;
				out = new PaqueteDatagrama((char*)&sa, sizeof(sa), clientIp, clientPort);
				break;
			case R_ASTEROID:
				sa.answer = R_ASTEROID;
				sa.count = asteroids[requestOpt]->getPointCount();
				asteroids[requestOpt]->setAngle(angle);
				asteroids[requestOpt]->setX(xast);
				//angle++;
				xast++;
				angle = angle % 360;
				xast = xast % G_WINDOW_WIDTH;
				memcpy(sa.points, asteroids[requestOpt]->getPoints(), sa.count*sizeof(XPoint));
				out = new PaqueteDatagrama((char*)&sa, sizeof(sa), clientIp, clientPort);
				break;
		}
		
		skt.envia(out);
		free(out);
		
		
		
	} while(request != R_ENDGAME);
	
}
