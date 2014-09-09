#include <iostream>
#include "PoligonoIrregular.h"
#include <cstdlib>
using namespace std;

const int M_CORDS = 101;
const int M_VERTS = 10;

double randomValue();

int main(int argc, char ** argv)
{
	srand(time(NULL));
	int N = 0,m;
	double x, y;
	if(argc != 2)
		cin >> N;
	else
		N = atoi(argv[1]);
	PoligonoIrregular p;
	m = N;
	for(int i = 0; i < m; i++){
		x = randomValue();
		y = randomValue();
		p.addVertice(Coordenada(x,y));
	}
	p.imprimeVertices();
	p.ordenaA();
	p.imprimeVertices();
	return 0;
}

double randomValue(){
	return ((double)(rand() % M_CORDS) * (rand() % 2 ? 1 : -1)) + (((double)(rand() % M_CORDS)) / 100);
}
