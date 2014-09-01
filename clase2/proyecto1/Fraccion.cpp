#include "Fraccion.h"
#include <iostream>
using namespace std;

Fraccion::Fraccion(int numerador, int denominador)
{
	this->numerador = numerador;
	this->denominador = denominador;
}

double Fraccion::getDouble() {
	return ((double)numerador) / denominador;
}

int Fraccion::mcd() {
	int b = numerador, t;
	int a = denominador;
	while(b){
       t = b;
       b = a % b;
       a = t;
   }
   return a;
}

void Fraccion::imprime() {
	std::cout << numerador  << "/" << denominador;
}

void Fraccion::imprimeMinima() {
	int gcd = mcd();
	std::cout << (numerador / gcd) << "/" << (denominador / gcd);
}
