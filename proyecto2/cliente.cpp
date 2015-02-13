#pragma GCC diagnostic ignored "-Wwrite-strings"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "SpaceShip.h"
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include "GameCommon.h"

unsigned long ObtieneColor( Display* dis, char* color_name );

char clientIp[16];
int clientPort;

int main()
{
	int delay = 5;
	int ans = 0;
	SocketDatagrama skt = SocketDatagrama(C_CLIENT_PORT);
	skt.setReceiveTime(0.5);
	ClientRequest rq;
	rq.request = R_STARTGAME;
	PaqueteDatagrama * out = new PaqueteDatagrama((char*)&rq, sizeof(rq), "127.0.0.1", C_SERVER_PORT);
	PaqueteDatagrama in = PaqueteDatagrama(sizeof(ServerAnswer));
	skt.envia(out);
	skt.recibe(&in);
	ServerAnswer * answer = (ServerAnswer *)in.obtieneDatos();
	unsigned long long int asteroidNodes;
	int answerCount;
	if(answer->answer  == R_STARTGAME)
	{
		Display *disp = NULL;
		Window ventana;
		XColor color;
		disp = XOpenDisplay(NULL);
		ventana = XCreateSimpleWindow (disp, XDefaultRootWindow (disp), 0, 0, G_WINDOW_WIDTH, G_WINDOW_HEIGHT, 1,1,BlackPixel (disp, DefaultScreen(disp)));
		XMapWindow (disp, ventana);
		int playing = 1;
		while(playing){
			
			
			rq.request = R_FULLFRAME;
			out = new PaqueteDatagrama((char*)&rq, sizeof(rq), "127.0.0.1", C_SERVER_PORT);
			skt.envia(out);
			ans = skt.recibe(&in);
			if(ans == -1)
				printf("Lost package\n");
			answer = (ServerAnswer *)in.obtieneDatos();
			answerCount = answer->asteroidCount;
			XSetForeground( disp, XDefaultGC (disp, DefaultScreen(disp)), CC_GREEN);
			
			// Nave espacial:
			XDrawLines(disp, ventana,XDefaultGC (disp, DefaultScreen(disp)), answer->points, 4, CoordModeOrigin);
			
			// Asteroides:
			asteroidNodes = answer->asteroidNodes;
			while(asteroidNodes)
			{
				int aa = asteroidNodes % 10;
				asteroidNodes /= 10;
				XDrawLines(disp, ventana,XDefaultGC (disp, DefaultScreen(disp)), answer->points + (answerCount - aa), aa, CoordModeOrigin);
				answerCount -= aa;
			}
			
			free(out);
			XSetForeground( disp, XDefaultGC (disp, DefaultScreen(disp)), CC_GREEN);
			usleep(delay * 500);	
			XClearWindow(disp,ventana);
		}		
	}
	
	
}

unsigned long ObtieneColor( Display* dis, char* color_name )
{
	Colormap cmap;
	XColor color_cercano, color_verdadero;
	cmap = DefaultColormap( dis, 0 );
	XAllocNamedColor( dis, cmap, color_name, &color_cercano, &color_verdadero );
	return( color_cercano.pixel );
}
