#include "Paralelepipedo.h"

Paralelepipedo::Paralelepipedo() {
	
}

Paralelepipedo::Paralelepipedo(Vector A, Vector B, Vector C) : a(A), b(B), c(C){
	parals[0] = Paralelogramo(A,B);
	parals[1] = Paralelogramo(B,C);
	parals[2] = Paralelogramo(A,C);
}

double Paralelepipedo::getArea() {
	double res = 0;
	for(int i = 0; i < 3; i++){
		res += parals[i].getArea() * 2;
	}
	return res;
}

double Paralelepipedo::getVolumen() {
	// Producto mixto: (Regla de Sarrus)
	return 	a.X() * b.Y() * c.Z() + a.Y() * b.Z() * c.X() + b.X() * c.Y() * a.Z()
			- a.Z() * b.Y() * c.X() - b.Z() * c.Y() * a.X() - a.Y() * b.X() * c.Z();
}
