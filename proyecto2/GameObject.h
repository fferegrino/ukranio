#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__
#include <X11/Xlib.h>


class GameObject {
	public:
		GameObject(int, int);
		virtual void setAngle(int);
		virtual XPoint * getPoints();
		virtual int getPointsNumber();
	protected: 
		int _x;
		int _y;
		int _angle;
		int _pointsNumber;
};
#endif
