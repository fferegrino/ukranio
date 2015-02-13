#ifndef __GAMECOMMON_H__
#define __GAMECOMMON_H__

#define R_STARTGAME 0x01
#define R_SPACESHIP 0x02
#define R_ASTEROID 0x03
#define R_ASTEROID_COUNT 0x04
#define R_FULLFRAME 0x05
#define R_ENDGAME 0x00

#define C_SERVER_PORT 7654
#define C_CLIENT_PORT 4567

#define G_WINDOW_WIDTH 	600
#define G_WINDOW_HEIGHT 600

#define MAX_ASTEROID_NODES 9
#define MIN_ASTEROID_NODES 4
#define MAX_ASTEROID_RADIO 40
#define MIN_ASTEROID_RADIO 20
#define MAX_ASTEROID_COUNT 19
#define MIN_ASTEROID_COUNT 2

#define CC_GREEN BlackPixel(disp,0)^ObtieneColor( disp, "green")
#define CC_YELLOW BlackPixel(disp,0)^ObtieneColor( disp, "yellow")
#define CC_RED BlackPixel(disp,0)^ObtieneColor( disp, "red")


struct ServerAnswer 
{
	short answer;
	short asteroidCount;
	unsigned long long int asteroidNodes;
	XPoint points[174];
};

struct ClientRequest
{
	int request;
	int requestOpt;
};


#endif
