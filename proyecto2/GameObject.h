#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__
#include <X11/Xlib.h>


class GameObject {
	public:
		GameObject(int, int);
		GameObject(int, int, int, int, int, int);
		virtual void setAngle(int);
		virtual XPoint * getPoints();
		virtual int getPointCount();
		virtual void setX(int);
		virtual void setY(int);
		virtual int getX();
		virtual int getY();
	protected: 
		int _x;
		int _y;
		int _x1;
		int _y1;
		int _x2;
		int _y2;
		int _angle;
		int _pointCount;
		XPoint * points;
};
#endif
