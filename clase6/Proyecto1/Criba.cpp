#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "SupuestoPrimo.h"
using namespace std;
vector<SupuestoPrimo> primos;

int main(int argc, char ** argv) {
	int N = 0;
	if(argc != 2)
		cin >> N;
	else
		N = atoi(argv[1]);
	for(int i = 0; i <= N; i++){
		primos.push_back(SupuestoPrimo(i));
	}
	for(int i = 2; i < N; i++){
		for(int j = 2; j * i < N ; j++){
			primos[i * j].setPrimo(false);
		}
	}
	for(int i = 1; i < N; i++){
		if(primos[i].esPrimo())
			cout << primos[i].getValor() << " " ;
	}
	cout << endl;
}
