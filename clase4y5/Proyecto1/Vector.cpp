#include "Vector.h"

Vector::Vector() : x(0), y(0), z(0) {
	
}

Vector::Vector(double X, double Y, double Z) : x(X), y(Y), z(Z){
	
}

double Vector::X(){
	return x;
}

double Vector::Y(){
	return y;
}

double Vector::Z(){
	return z;
}
