#include "Coordenada.h"
#ifndef __RECTANGULO_H__
#define __RECTANGULO_H__
class Rectangulo
{
	private:
		Coordenada uno;
		Coordenada dos;
	public:
		Rectangulo();
		Rectangulo(double, double, double, double, double, double);
		Rectangulo(Coordenada c1, Coordenada c2);
		double obtieneArea();
		double obtieneVolumen();
		void imprimeEsq();
		Coordenada coordenadaUno();
		Coordenada coordenadaDos();
};
#endif
