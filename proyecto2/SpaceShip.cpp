#include "SpaceShip.h"
#include <cmath>
#define PI 3.14159265


SpaceShip::SpaceShip(int x, int y) :
	GameObject(x,y)
{
	_angle = 0;
	_size = 30;
	_pointCount = 4;
	points  = (XPoint *)malloc(sizeof(XPoint) * _pointCount);
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
	
	
	
	points[0].x = ((_size) * std::cos ( _angle * PI / 180.0 )) + _x;
	points[0].y = ((_size) * std::sin ( _angle * PI / 180.0 ))  + _y;
	
	points[1].x = ((_size) * std::cos ( (_angle + 120) * PI / 180.0 ))+ _x;
	points[1].y = ((_size) * std::sin ( (_angle + 120) * PI / 180.0 )) + _y;
	
	points[2].x = ((_size) * std::cos ( (_angle + 240) * PI / 180.0 )) + _x;
	points[2].y = ((_size) * std::sin ( (_angle + 240) * PI / 180.0 )) + _y;
	
	points[3].x = ((_size) * std::cos ( _angle * PI / 180.0 )) + _x;
	points[3].y = ((_size) * std::sin ( _angle * PI / 180.0 )) + _y;
	
	return points;
}

int SpaceShip::getPointCount()
{
	return _pointCount;
}
