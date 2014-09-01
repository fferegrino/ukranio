#include "Rectangulo.h"
#include "Coordenada.h"
#include <vector>

#ifndef __OCTOEDRO_H__
#define __OCTOEDRO_H__

class Octoedro 
{
	private:
		Rectangulo rects[6];
		std::vector<Coordenada> vertices;
		Coordenada uno;
		Coordenada dos;
	public:
		Octoedro(Coordenada uno, Coordenada dos);
		double obtieneArea();
		double obtieneVolumen();
		std::vector<Coordenada> obtieneVertices();
};

#endif
