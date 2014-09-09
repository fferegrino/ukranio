#include "Coordenada.h"
#include <cmath>
// Coordenada:
Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy) { distanciaOrigen = sqrt(xx * xx + yy * yy); }
double Coordenada::X() { return x; }
double Coordenada::Y() { return y; }
double Coordenada::D() { return distanciaOrigen; }
bool Coordenada::operator <(const Coordenada& other) const 
{ 
	return distanciaOrigen < other.distanciaOrigen; 
}
