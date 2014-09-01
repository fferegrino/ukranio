#include <iostream>
#include <cstdlib>
//#define REFERENCIA
using namespace std;
class Fecha
{
	private:
		int dia;
		int mes;
		int anio;
		unsigned long long int ar[10000];
		unsigned long long int mr[10000];
		unsigned long long int dr[10000];
	public:
		Fecha(int = 3, int = 4, int = 2014);
		void inicializaFecha(int, int, int);
		void muestraFecha();		
		int compara(Fecha other);	
		int compara(Fecha *other);			
		int comparaRef(Fecha& other);
};
Fecha::Fecha(int dd, int mm, int aaaa)
{
	mes = mm;
	dia = dd;
	anio = aaaa;
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
	cout << "La fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;
	return; 
}

int Fecha::compara(Fecha other){
	if(dia == other.dia && mes == other.mes && anio == other.anio)
		return 0;
	if(anio == other.anio){
			if(mes == other.mes){
				if(dia > other.dia)
					return 1;
				return -1;
			}else{
				if(mes > other.mes)
					return 1;
				return -1;
			}
	}
	else
	{
		if(anio > other.anio)
			return 1;
		return -1;
	}

}
		
int Fecha::comparaRef(Fecha& other){
	if(dia == other.dia && mes == other.mes && anio == other.anio)
		return 0;
	if(anio == other.anio){
			if(mes == other.mes){
				if(dia > other.dia)
					return 1;
				return -1;
			}else{
				if(mes > other.mes)
					return 1;
				return -1;
			}
	}
	else
	{
		if(anio > other.anio)
			return 1;
		return -1;
	}
}

int Fecha::compara(Fecha *other){
	if(dia == other->dia && mes == other->mes && anio == other->anio)
		return 0;
	if(anio == other->anio){
			if(mes == other->mes){
				if(dia > other->dia)
					return 1;
				return -1;
			}else{
				if(mes > other->mes)
					return 1;
				return -1;
			}
	}
	else
	{
		if(anio > other->anio)
			return 1;
		return -1;
	}

}


#ifdef NORMAL
int masVieja(Fecha fecha1, Fecha fecha2);
#endif
#ifdef REFERENCIA
int masVieja(Fecha& fecha1, Fecha& fecha2);
#endif
#ifdef C_STYLE
int masVieja(Fecha* fecha1, Fecha* fecha2);
#endif

int main() {
	srand(time(0));
	int N;
	cin >> N; N++;
	Fecha a, b;
	while(--N){
		int dia1 = (rand() % 31) + 1;
		int anio1 = (rand() % 2014) + 1;
		int mes1 = (rand() % 12) + 1;
		
		int dia2 = (rand() % 31) + 1;
		int anio2 = (rand() % 2014) + 1;
		int mes2 = (rand() % 12) + 1;
		a.inicializaFecha(dia1, mes1, anio1);
		b.inicializaFecha(dia2, mes2, anio2);
		/*
		cout << "La fecha 1 es: ";
		a.muestraFecha();
		cout << "La fecha 2 es: ";
		b.muestraFecha();
		*/
		#ifdef C_STYLE
		int res = masVieja(&a,&b);
		#else
		int res = masVieja(a,b);
		#endif
		/*
		cout << "Resultado " << res << ": ";
		if(res == 0){
			cout << "las fechas son iguales\n\n";
		}else if(res < 0){
			cout << "1 es menor que 2\n\n";
		}else
			cout << "1 es mayor que 2\n\n";
		*/
	}
}
#ifdef NORMAL
int masVieja(Fecha fecha1, Fecha fecha2){
	return fecha1.compara(fecha2);
}
#endif
#ifdef REFERENCIA
int masVieja(Fecha& fecha1, Fecha& fecha2){
	return fecha1.comparaRef(fecha2);
}
#endif
#ifdef C_STYLE
int masVieja(Fecha* fecha1, Fecha* fecha2){
	return fecha1->compara(fecha2);
}
#endif
