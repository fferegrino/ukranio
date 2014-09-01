#include <iostream>
#include "Fecha.h"
using namespace std;

int main() {
	Fecha a, b, c(-21, 9, 1973);
	b.inicializaFecha(7, 6 , 2000);
	a.muestraFecha();
	b.muestraFecha();
	c.muestraFecha(); 
	cout << a.convierte() << endl;
	cout << b.convierte() << endl;
	cout << c.convierte() << endl;
}
