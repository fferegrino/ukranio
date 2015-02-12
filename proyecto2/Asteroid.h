#ifndef __ASTEROID_H__
#define __ASTEROID_H__

#include "GameObject.h"
#include <unistd.h>
#include <cstdlib>

class Asteroid : public GameObject {

	public: 
		Asteroid(int, int, int);
		Asteroid(int, int, int, int, int);
		void setAngle(int);
		void setSize(int);
		XPoint * getPoints();
		int getPointCount();
		void addNextRadio(int r);
	private:
		int _size;
		int _ir;
		int * _radios;
};


#endif 

