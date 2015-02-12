#include "Asteroid.h"
#include <cmath>
#define PI 3.14159265


Asteroid::Asteroid(int pointCount, int x, int y) :
	GameObject(x,y)
{
	_angle = 0;
	_size = 30;
	_pointCount = pointCount;
	_radios = (int *)malloc(sizeof(int) * _pointCount);
	points  = (XPoint *)malloc(sizeof(XPoint) * _pointCount);
}

Asteroid::Asteroid(int pointCount, int x1, int y1, int x2, int y2) :
	GameObject(x1, y1, x1, x2, y1, y2)
{
	_angle = 0;
	_size = 30;
	_pointCount = pointCount;
	_radios = (int *)malloc(sizeof(int) * _pointCount);
	points  = (XPoint *)malloc(sizeof(XPoint) * _pointCount);
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
	int a = 360 / (_pointCount - 1);
	
	//Ecuacion de la recta:
	int xp = _x2 - _x1;
	int yp = _y2 - _y1;
	int sol = (-1 * xp * _y1) + yp * _x1 - yp * _x;
	if(xp != 0)
		_y = -1 * sol / xp;
	
	for(int i = 0; i < _pointCount - 1 ; i++)
	{
		points[i].x = ((_radios[i]) * std::cos ( _angle + (i*a) * PI / 180.0 )) + _x;
		points[i].y = ((_radios[i]) * std::sin ( _angle + (i*a) * PI / 180.0 )) + _y;
	}
	
	points[_pointCount - 1].x = points[0].x;
	points[_pointCount - 1].y = points[0].y;
	
	return points;
}


void Asteroid::addNextRadio(int r)
{
	if(_ir < _pointCount)
	{
		_radios[_ir++] = r;
	}
}

int Asteroid::getPointCount()
{
	return _pointCount;
}
