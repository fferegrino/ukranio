#ifndef __ASTEROID_H__
#define __ASTEROID_H__

#include "GameObject.h"
#include <unistd.h>
#include <cstdlib>

class Asteroid : public GameObject {

	public: 
		Asteroid(int, int);
		Asteroid(int, int, int, int);
		void setAngle(int);
		void setSize(int);
		XPoint * getPoints();
		int getPointsNumber();
	private:
		int _size;
		int _x1;
		int _y1;
		int _x2;
		int _y2;
};


#endif 

