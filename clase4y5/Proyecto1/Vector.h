#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "Vector.h"

class Vector
{
	private:
		double x, y, z;
	public:
		Vector();
		Vector(double X, double Y, double Z);
		double X();
		double Y();
		double Z();
};

#endif
