#include "GameObject.h"

GameObject::GameObject(int x, int y) :
	_x(x), _y(y)
{
	
}

int GameObject::getPointsNumber()
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




