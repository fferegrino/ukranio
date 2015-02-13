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
	int answerCount = 0;
	unsigned long long int asteroidLoc = 0;
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
				//sa.count = 0;
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
			case R_FULLFRAME:
				answerCount = 0;
				asteroidLoc = 0;
				sa.answer = R_FULLFRAME;
				answerCount = spaceShip->getPointCount();
				memcpy(sa.points, spaceShip->getPoints(), answerCount * sizeof(XPoint));
				xast = (++xast) % G_WINDOW_WIDTH;
				for(int ii = 0; ii < asteroidC; ii++)
				{
					asteroidLoc *= 10;
					asteroidLoc += asteroids[ii]->getPointCount();
					asteroids[ii]->setX(xast);
					memcpy(sa.points + answerCount, asteroids[ii]->getPoints(), asteroids[ii]->getPointCount()*sizeof(XPoint));	
					answerCount += asteroids[ii]->getPointCount();
				}
				sa.asteroidCount = answerCount;
				sa.asteroidNodes = asteroidLoc;
				out = new PaqueteDatagrama((char*)&sa, sizeof(sa), clientIp, clientPort);
				break;
		}
		
		skt.envia(out);
		free(out);
		
		
		
	} while(request != R_ENDGAME);
	
}
