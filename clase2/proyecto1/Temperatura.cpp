#include "Temperatura.h"
#include <iostream>
using namespace std;

Temperatura::Temperatura(double kelvin)
{
	this->kelvin = kelvin;
	this->celsius = kelvin - 273.15;
	this->farenheit =  (celsius * 1.8) + 32.00;
}

void Temperatura::setTempKelvin(double kelvin){
	this->kelvin = kelvin;
	this->celsius = kelvin - 273.15;
	this->farenheit =  (celsius * 1.8) + 32.00;
}
void Temperatura::setTempFarenheit(double farenheit){
	this->farenheit = farenheit;
	this->celsius = (farenheit - 32) / 1.8;
	this->kelvin = celsius + 273.15;
}
void Temperatura::setTempCelsius(double celsius){
	this->celsius = celsius;
	this->farenheit =  (celsius * 1.8) + 32.00;
	this->kelvin = celsius + 273.15;
}

double Temperatura::getCelsius() {
	return celsius;
}
double Temperatura::getFarenheit() {
	return farenheit;
}
double Temperatura::getKelvin() {
	return kelvin;
}
void Temperatura::imprimeK(){
	std::cout << kelvin << " grados kelvin\n";
}
void Temperatura::imprimeC() {
	std::cout << celsius << " grados centígrados\n";
}
void Temperatura::imprimeF() {
	std::cout << farenheit << " grados farenheit\n";
}


