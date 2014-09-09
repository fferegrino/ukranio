#include "PoligonoIrregular.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>

// Poligono irregular:
PoligonoIrregular::PoligonoIrregular() { }
void PoligonoIrregular::addVertice(Coordenada c) {
	totalVertices++;
	cords.push_back(c);
}

int PoligonoIrregular::totalVertices = 0;
int PoligonoIrregular::getTotalVertices() {
	return totalVertices;
}

void PoligonoIrregular::imprimeVertices(){
	std::cout << "Las coordenadas son:\n";
	std::vector<Coordenada>::iterator i;
	for(i = cords.begin(); i != cords.end( ); i++)
	{
		std::cout << "(" << (*i).X() << ", " << (*i).Y() << ") distancia al origen: " << (*i).D() << std::endl;
	}
	std::cout << std::endl;
}

void PoligonoIrregular::ordenaA() {
	std::sort(cords.begin(), cords.end());
}
