#ifndef __COORDENADA_H__
#define __COORDENADA_H__

class Coordenada
{
	private:
		double x;
		double y;
		double z;
	public:
		Coordenada(double = 0, double = 0,double = 0);
		void imprimeCoord();
		double X();
		double Y();
		double Z();
};

#endif
