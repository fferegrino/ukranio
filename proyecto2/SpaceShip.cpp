#include "SpaceShip.h"
#include <cmath>
#define PI 3.14159265


SpaceShip::SpaceShip(int x, int y) :
	GameObject(x,y)
{
	_angle = 0;
	_size = 30;
	_pointsNumber = 4;
}

void SpaceShip::setAngle(int angle)
{
	_angle = angle;
}
void SpaceShip::setSize(int size)
{
	_size = size;
}

XPoint * SpaceShip::getPoints()
{
	int height = 30;
	XPoint * puntos  = (XPoint *)malloc(sizeof(XPoint) * _pointsNumber);
	
	
	puntos[0].x = ((_size) * std::cos ( _angle * PI / 180.0 )) + _x;
	puntos[0].y = ((_size) * std::sin ( _angle * PI / 180.0 ))  + _y;
	
	puntos[1].x = ((_size) * std::cos ( (_angle + 120) * PI / 180.0 ))+ _x;
	puntos[1].y = ((_size) * std::sin ( (_angle + 120) * PI / 180.0 )) + _y;
	
	puntos[2].x = ((_size) * std::cos ( (_angle + 240) * PI / 180.0 )) + _x;
	puntos[2].y = ((_size) * std::sin ( (_angle + 240) * PI / 180.0 )) + _y;
	
	puntos[3].x = ((_size) * std::cos ( _angle * PI / 180.0 )) + _x;
	puntos[3].y = ((_size) * std::sin ( _angle * PI / 180.0 )) + _y;
	
	return puntos;
}

int SpaceShip::getPointsNumber()
{
	return _pointsNumber;
}
