#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <ctype.h>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include "SpaceShip.h"

void * inputThread(void *);
void * graphicsThread(void *);

const int displayWidth = 900;
const int delay = 10;
const int displayHeight = 900;

unsigned long ObtieneColor( Display* dis, char* color_name )
{
	Colormap cmap;
	XColor color_cercano, color_verdadero;
	cmap = DefaultColormap( dis, 0 );
	XAllocNamedColor( dis, cmap, color_name, &color_cercano, &color_verdadero );
	return( color_cercano.pixel );
}

struct GameThreadAux {
	Display * display;
	Window * ventana;
};

int main()
{
	int ans = XInitThreads();
	printf("%d\n", ans);
	Display *disp = NULL;
	Window ventana;
	XColor color;
	disp = XOpenDisplay(NULL);
	ventana = XCreateSimpleWindow (disp, XDefaultRootWindow (disp), 0, 0, displayWidth, displayHeight, 1,1,BlackPixel (disp, DefaultScreen(disp)));
	XSelectInput(disp, ventana, ButtonPressMask|StructureNotifyMask|KeyPressMask|KeyReleaseMask|KeymapStateMask);
	XMapWindow (disp, ventana);
	
	GameThreadAux aux;
	aux.display = disp;
	aux.ventana = &ventana;
	
	
	pthread_t * gameThreads = (pthread_t *) malloc(sizeof(pthread_t) * 2);
	pthread_create(&gameThreads[0], NULL, inputThread, (void *) &aux);
	pthread_create(&gameThreads[1], NULL, graphicsThread, (void *) &aux);
	
	for (int i=0; i<2; i++) 
		pthread_join(gameThreads[i], NULL);
	free(gameThreads);
	
	XDestroyWindow( disp , ventana );
	XCloseDisplay( disp );
	return(0);
}

bool up;
bool down;

void * inputThread(void * aux)
{
	XEvent ev;
	Display * disp = ((GameThreadAux *) aux)->display;
	while(1)
	{
		XNextEvent(disp, &ev);
		if(ev.type == KeyRelease)
		{
			up = ev.xkey.keycode == 111;
			down = ev.xkey.keycode == 116;
		}
	}
}

void * graphicsThread(void * aux)
{
	
	Display * disp = ((GameThreadAux *) aux)->display;
	Window ventana = *(((GameThreadAux *) aux)->ventana);
	//XMapWindow (disp, ventana);
	
	SpaceShip spaceship = SpaceShip(displayWidth  / 2 ,displayHeight / 2);
	int t = 0;
	int s = 50;
	while(1)
	{
		printf("G");
		XSetForeground( disp, XDefaultGC (disp, DefaultScreen(disp)), BlackPixel(disp,0)^ObtieneColor( disp, "aqua"));
		XClearWindow(disp,ventana);
		spaceship.setAngle(t++);
		t %= 360;
		if(up)
			s++;
		if(down)
			s--;
		spaceship.setSize(s);
		XDrawLines(disp, ventana,XDefaultGC (disp, DefaultScreen(disp)), spaceship.getPoints(), spaceship.getPointsNumber(), CoordModeOrigin);
		usleep(41666);	
	}
}
