#define R_STARTGAME 0x01
#define R_SPACESHIP 0x02
#define R_ASTEROID 0x03
#define R_ASTEROID_COUNT 0x04
#define R_ENDGAME 0x00

#define C_SERVER_PORT 7654
#define C_CLIENT_PORT 4567

#define G_WINDOW_WIDTH 500
#define G_WINDOW_HEIGHT 500


struct ServerAnswer 
{
	int answer;
	int count;
	XPoint points[10];
};

struct ClientRequest
{
	int request;
	int requestOpt;
};
