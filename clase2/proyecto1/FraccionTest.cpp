#include <iostream>
#include "Fraccion.h"
using namespace std;

int main() {
	Fraccion t(15, 3);
	std::cout << t.getDouble() << endl;
	t.imprimeMinima();
	std::cout << endl;
	t.imprime();
	std::cout << endl;
}
