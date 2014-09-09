#ifndef __SUPUESTOPRIMO_H__
#define __SUPUESTOPRIMO_H__

class SupuestoPrimo {
	private:
		int _valor;
		bool _esPrimo;
	public:
		SupuestoPrimo(int valor);
		SupuestoPrimo();
		void setValor(int valor);
		void setPrimo(bool esPrimo);
		bool esPrimo();
		int getValor();
};

#endif
