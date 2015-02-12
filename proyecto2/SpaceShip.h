#ifndef __SPACESHIP_H__
#define __SPACESHIP_H__

#include "GameObject.h"
#include <unistd.h>
#include <cstdlib>

class SpaceShip : public GameObject {

	public: 
		SpaceShip(int, int);
		void setAngle(int);
		void setSize(int);
		XPoint * getPoints();
		int getPointCount();
	private:
		int _size;
};


#endif 

