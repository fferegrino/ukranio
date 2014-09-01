#include "Coordenada.h"
#ifndef __RECTANGULO_H__
#define __RECTANGULO_H__
class Rectangulo
{
	private:
		Coordenada superiorIzq;
		Coordenada inferiorDer;
	public:
		Rectangulo();
		Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer);
		Rectangulo(Coordenada c1, Coordenada c2);
		double obtieneArea();
		void imprimeEsq();
		Coordenada obtieneSupIzq();
		Coordenada obtieneInfDer();
};
#endif
