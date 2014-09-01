#include "Fecha.h"
#include <iostream>
#include <cstdlib>
using namespace std;
Fecha::Fecha(int dd, int mm, int aaaa)
	: dia(dd), mes(mm), anio(aaaa)
{
	if(dd < 1 || dd > 31){
		cout << "Día inválido: " << dd << endl;
		exit(1);
	}
	if(mm < 1 || mm > 31){
		cout << "Mes inválido " << mm << endl;
		exit(1);
	}
}

void Fecha::inicializaFecha(int dd, int mm, int aaaa)
{
	anio = aaaa;
	mes = mm;
	dia = dd; 
	return;
}

void Fecha::muestraFecha()
{
	cout << "La fecha es: " << dia << "-" << mes << "-" << anio;
	return; 
}

int Fecha::convierte(){
	return anio*10000+mes*100+dia;
}
