#include <iostream>
#include "Rectangulo.h"
using namespace std;

int main( )
{
	Rectangulo rectangulo1(Coordenada(3.6056,56.310),Coordenada(6.0828,9.4623));
	double ancho, alto; 
	cout << "Calculando el área de un rectángulo dadas sus coordenadas en un plano cartesiano:\n"; 
	rectangulo1.imprimeEsq();
	cout << "El área del rectángulo es = " << rectangulo1.obtieneArea() << endl;
	return 0;
} 


