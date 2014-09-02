#ifndef __PARALELEPIPEDO_H__
#define __PARALELEPIPEDO_H__

#include "Vector.h"
#include "Paralelogramo.h"

class Paralelepipedo
{
	private:
		Vector a, b, c;
		Paralelogramo parals[3];
	public:
		Paralelepipedo();
		Paralelepipedo(Vector A, Vector B, Vector C);
		double getArea();
		double getVolumen();
};

#endif

