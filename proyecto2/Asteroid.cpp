#include "Asteroid.h"
#include <cmath>
#define PI 3.14159265


Asteroid::Asteroid(int x, int y) :
	GameObject(x,y)
{
	_angle = 0;
	_size = 30;
	_pointsNumber = 7;
	points  = (XPoint *)malloc(sizeof(XPoint) * _pointsNumber);
}

Asteroid::Asteroid(int x1, int y1, int x2, int y2) :
	GameObject(x1,y1), _x2(x2), _y2(y2), _x1(x1), _y1(y1)
{
	_angle = 0;
	_size = 30;
	_pointsNumber = 7;
	points  = (XPoint *)malloc(sizeof(XPoint) * _pointsNumber);
}

void Asteroid::setAngle(int angle)
{
	_angle = angle;
}
void Asteroid::setSize(int size)
{
	_size = size;
}

XPoint * Asteroid::getPoints()
{
	int height = 30;
	int a = 360 / (_pointsNumber - 1);
	
	//Ecuacion de la recta:
	int xp = _x2 - _x1;
	int yp = _y2 - _y1;
	int sol = (-1 * xp * _y1) + yp * _x1 - yp * _x;
	_y = -1 * sol / xp;
	
	for(int i = 0; i < _pointsNumber ; i++)
	{
		points[i].x = ((_size) * std::cos ( _angle + (i*a) * PI / 180.0 )) + _x;
		points[i].y = ((_size) * std::sin ( _angle + (i*a) * PI / 180.0 )) + _y;
	}
	
	return points;
}

int Asteroid::getPointsNumber()
{
	return _pointsNumber;
}
