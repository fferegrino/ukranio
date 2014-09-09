#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

const int M_CORDS = 100;
const int M_VERTS = 10;

class Coordenada
{
	private:
		double x;
		double y;
	public:
		Coordenada(double = 0, double = 0);
		double X();
		double Y();
};

class PoligonoIrregular
{
	private:
		vector<Coordenada> cords;
		static int totalVertices;
	public:
		PoligonoIrregular();
		void imprimeVertices();
		void addVertice(Coordenada c);
		static int getTotalVertices();
};

int main(int argc, char ** argv)
{
	srand(time(NULL));
	int N = 0,m, x, y;
	vector<PoligonoIrregular> polys;
	if(argc != 2)
		cin >> N;
	else
		N = atoi(argv[1]);
	int ii = 0;
	PoligonoIrregular p;
	m = N; //(rand() % M_VERTS) + 1;
	#if DEBUG
	cout << "Poligono creado con " << m << " vertices:\n";
	#endif
	for(int i = 0; i < m; i++){
		x = (rand() % M_CORDS) * (rand() % 2 ? 1 : -1) ;
		y = (rand() % M_CORDS) * (rand() % 2 ? 1 : -1);
		#if DEBUG
		cout << "\tVertice "<< x << ", "<< y << " agregado\n";
		#endif
		p.addVertice(Coordenada(x,y));
	}
	p.imprimeVertices();
	return 0;
} 

// Coordenada:
Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy) { }
double Coordenada::X() { return x; }
double Coordenada::Y() { return y; }

// Poligono irregular:
PoligonoIrregular::PoligonoIrregular() { }
void PoligonoIrregular::addVertice(Coordenada c) {
	totalVertices++;
	cords.push_back(c);
}
int PoligonoIrregular::totalVertices = 0;
int PoligonoIrregular::getTotalVertices() {
	return totalVertices;
}
void PoligonoIrregular::imprimeVertices() {
	cout << "Las coordenadas son: ";
	for(int i = 0; i < cords.size(); i++)
	{
		cout << "(" << cords[i].X() << ", " << cords[i].Y() << ")";
		if(i + 1 < cords.size()) cout << ", "; else cout << ".";
	}
	cout << endl;
}

