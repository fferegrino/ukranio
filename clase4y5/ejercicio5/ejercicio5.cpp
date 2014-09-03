#include "Octoedro.h"
#include <iostream>
#include <vector>

int main(){
	Octoedro o(Coordenada(1,1,1), Coordenada(3,3,3));
	std::cout << "Volumen: " << o.obtieneVolumen() << std::endl;
	std::cout << "Area: " << o.obtieneArea() << std::endl;
	std::vector<Coordenada> verts = o.obtieneVertices();
	std::cout << "Las coordenadas son: " << std::endl;
	for(int i = 0; i < verts.size(); i++){
		std::cout << "\t(" << verts[i].X() << ", "<< verts[i].Y() << ", "<< verts[i].Z() << ")"<< std::endl;
	}
	return 0;
}
