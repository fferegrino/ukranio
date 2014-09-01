#ifndef __FRACCUON_H__
#define __FRACCION_H__
class Fraccion
{
	private:
		int denominador;
		int numerador;
		int mcd();
	public:
		Fraccion(int numerador, int denominador);
		double getDouble();
		void imprimeMinima();
		void imprime();
		
};
#endif
