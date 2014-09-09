#include "Coordenada.h"
#include <vector>
class PoligonoIrregular
{
	private:
		std::vector<Coordenada> cords;
		static int totalVertices;
	public:
		PoligonoIrregular();
		void imprimeVertices();
		void addVertice(Coordenada c);
		void ordenaA();
		static int getTotalVertices();
};
