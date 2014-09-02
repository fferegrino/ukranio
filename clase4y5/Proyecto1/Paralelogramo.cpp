#include "Paralelogramo.h"
#include <cmath>

Paralelogramo::Paralelogramo(Vector A, Vector B) : a(A), b(B) {
	
}

Paralelogramo::Paralelogramo() {
	
}

double Paralelogramo::getArea(){
	// Producto cruz:
	double i = a.Y() * b.Z() - a.Z() * b.Y();
	double j = a.X() * b.Z() - a.Z() * b.X();
	double k = a.X() * b.Y() - a.Y() * b.X();
	return std::sqrt(i * i + j * j + k * k);
}
