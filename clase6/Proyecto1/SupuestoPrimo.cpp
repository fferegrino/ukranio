#include "SupuestoPrimo.h"

SupuestoPrimo::SupuestoPrimo(int valor) : _valor(valor) { 
	_esPrimo = true;
}

SupuestoPrimo::SupuestoPrimo() { 
	_esPrimo = true;
}

void SupuestoPrimo::setValor(int valor) { 
	_valor = valor; 
}

int SupuestoPrimo::getValor() { 
	return _valor; 
}

void SupuestoPrimo::setPrimo(bool esPrimo) { 
	_esPrimo = esPrimo; 
}

bool SupuestoPrimo::esPrimo() { 
	return _esPrimo; 
}
