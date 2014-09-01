#include "Coordenada.h"

Coordenada::Coordenada(double xx, double yy, double zz) : x(xx), y(yy), z(zz)
{ }

double Coordenada::X()
{
	return x;
}
double Coordenada::Y()
{
	return y;
}
double Coordenada::Z()
{
	return z;
}

