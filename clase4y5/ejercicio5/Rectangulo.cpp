#include "Rectangulo.h"
#include <iostream>
#include <cmath>
using namespace std;

Rectangulo::Rectangulo() : uno(0,0,0), dos(0,0,0)
{ }

Rectangulo::Rectangulo(double x1, double y1, double z1, double x2, double y2, double z2) : 
	uno(x1, y1, z1), dos(x2, y2, z2)
{ }


Rectangulo::Rectangulo(Coordenada c1, Coordenada c2) : uno(c1), dos(c2)
{ }

void Rectangulo::imprimeEsq()
{
	
}
double Rectangulo::obtieneArea(){
	
	double alto, ancho;
	if(uno.X() == dos.X()) {
		alto = abs(uno.Y() - dos.Y());
		ancho = abs(uno.Z() - dos.Z());
	}else if(uno.Y() == dos.Y()) {
		alto = abs(uno.X() - dos.X());
		ancho = abs(uno.Z() - dos.Z());
	}else {
		alto = abs(uno.X() - dos.X());
		ancho = abs(uno.Y() - dos.Y());
	}
	return alto * ancho;
}

Coordenada Rectangulo::coordenadaUno()
{
	return uno;
}
Coordenada Rectangulo::coordenadaDos()
{
	return dos;
}
