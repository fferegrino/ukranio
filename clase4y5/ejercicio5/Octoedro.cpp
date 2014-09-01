#include "Octoedro.h"
#include "Rectangulo.h"
#include <cmath>

Octoedro::Octoedro(Coordenada u, Coordenada d)
	: uno(u), dos(d)
{
	rects[0] = Rectangulo(uno.X(), uno.Y(), dos.Z(), dos.X(), dos.Y(), dos.Z()); // Cara superior
	rects[1] = Rectangulo(uno.X(), uno.Y(), uno.Z(), dos.X(), dos.Y(), uno.Z()); // Cara inferior
	
	rects[2] = Rectangulo(dos.X(), dos.Y(), uno.Z(), dos.X(), uno.Y(), dos.Z());
	rects[3] = Rectangulo(uno.X(), dos.Y(), uno.Z(), uno.X(), uno.Y(), dos.Z());
	
	rects[4] = Rectangulo(dos.X(), dos.Y(), uno.Z(), uno.X(), dos.Y(), dos.Z());
	rects[5] = Rectangulo(dos.X(), uno.Y(), uno.Z(), uno.X(), uno.Y(), dos.Z());
	
	vertices.push_back(Coordenada(uno.X(), uno.Y(), uno.Z()));
	vertices.push_back(Coordenada(uno.X(), uno.Y(), dos.Z()));
	vertices.push_back(Coordenada(uno.X(), dos.Y(), uno.Z()));
	vertices.push_back(Coordenada(uno.X(), dos.Y(), dos.Z()));
	vertices.push_back(Coordenada(dos.X(), uno.Y(), uno.Z()));
	vertices.push_back(Coordenada(dos.X(), uno.Y(), dos.Z()));
	vertices.push_back(Coordenada(dos.X(), dos.Y(), uno.Z()));
	vertices.push_back(Coordenada(dos.X(), dos.Y(), dos.Z()));
}


double Octoedro::obtieneVolumen(){
	double 	alto = uno.Z() - dos.Z()
			, ancho = uno.Y() - dos.Y()
			, largo = uno.X() - dos.X();
	return std::abs(alto * ancho * largo);
}


double Octoedro::obtieneArea(){
	double area = 0;
	for(int i  = 0; i < 6; i++){
		area += rects[i].obtieneArea();
	}
	return area;
}


std::vector<Coordenada> Octoedro::obtieneVertices(){
	return vertices;
}
