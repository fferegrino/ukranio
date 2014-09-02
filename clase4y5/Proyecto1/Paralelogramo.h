#ifndef __PARALELOGRAMO_H__
#define __PARALELOGRAMO_H__

#include "Vector.h"

class Paralelogramo
{
	private:
		Vector a, b;
	public:
		Paralelogramo();
		Paralelogramo(Vector A, Vector B);
		double getArea();
};

#endif

