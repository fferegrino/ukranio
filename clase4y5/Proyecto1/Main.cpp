#include <iostream>
#include "Vector.h"
#include "Paralelogramo.h"
#include "Paralelepipedo.h"

using namespace std;

int main() {
		Vector v1(2,0,0);
		Vector v2(0,2,0);
		Vector v3(0,0,2);
		Paralelepipedo p(v1, v2, v3);
		
		cout << p.getArea() << endl;
		cout << p.getVolumen() << endl;
}
