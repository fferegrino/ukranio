#include "GameObject.h"

GameObject::GameObject(int x, int y) :
	_x(x), _y(y)
{
	
}

GameObject::GameObject(int x, int y, int x1, int x2, int y1, int y2) :
	_x(x), _y(y), _x1(x1), _x2(x2), _y1(y1), _y2(y2)
{
	
}

int GameObject::getPointCount()
{
	return -1;
}

XPoint * GameObject::getPoints()
{
	return NULL;
}



void GameObject::setAngle(int ang)
{
	
}


void GameObject::setX(int x)
{
	_x= x;
}

void GameObject::setY(int y)
{
	_y = y;
}

int GameObject::getY()
{
	return _y;
}

int GameObject::getX()
{
	return _x;
}




