#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

const int M_CORDS = 10;
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
	int N = 0,m, x, y;
	vector<PoligonoIrregular> polys;
	if(argc != 2)
		cin >> N;
	else
		N = atoi(argv[1]);
	N++;
	#if RESERVE
	polys.reserve(N);
	//polys.resize(N);
	#endif
	int ii = 0;
	while(--N){
		PoligonoIrregular p;
		m = (rand() % M_VERTS) + 1;
		#if DEBUG
		cout << "Poligono creado con " << m << " vertices:\n";
		#endif
		for(int i = 0; i < m; i++){
			x = rand() % M_CORDS;
			y = rand() % M_CORDS;
			#if DEBUG
			cout << "\tVertice ("<< x << ", " << y << ") agregado\n";
			#endif
			p.addVertice(Coordenada(x,y));
		}
		
		#if RESERVE
		polys[ii++] = p;
		#else
		polys.push_back(p);
		#endif
	}
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

void PoligonoIrregular::imprimeVertices(){
	cout << "Las coordenadas son: ";
	for(int i = 0; i < cords.size(); i++)
	{
		cout << "(" << cords[i].X() << ", " << cords[i].Y() << ")";
		if(i + 1 < cords.size()) cout << ", "; else cout << ".";
	}
	cout << endl;
}

