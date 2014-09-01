#include "Coordenada.h"
#include <cmath>

Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy)
{ }
double Coordenada::obtenerX()
{
	return x * cos(y * M_PI / 180);
	//return x;
}
double Coordenada::obtenerY()
{
	return x * sin(y * M_PI / 180);
	//return y;
}
