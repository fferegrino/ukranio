#include <iostream>
#include "Temperatura.h"
using namespace std;

int main() {
	Temperatura t(1);
	t.imprimeK();
	t.imprimeC();
	t.imprimeF();
	t.setTempCelsius(37);
	t.imprimeK();
	t.imprimeC();
	t.imprimeF();
}
