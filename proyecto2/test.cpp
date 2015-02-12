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

unsigned long spaceShipColor;
unsigned long asteroidColor;
const int delay = 5;

int main()
{
	printf("XPoint:\t %3ld\n", 1024 / sizeof(XPoint));
}

unsigned long ObtieneColor( Display* dis, char* color_name )
{
	Colormap cmap;
	XColor color_cercano, color_verdadero;
	cmap = DefaultColormap( dis, 0 );
	XAllocNamedColor( dis, cmap, color_name, &color_cercano, &color_verdadero );
	return( color_cercano.pixel );
}
