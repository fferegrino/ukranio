#include <iostream>
using namespace std;
const double PI =  3.1415926;
int main()
{
	double r;
	cout << "Ingresa el radio:\n";
	cin >> r;
	cout << "El area es : " << r * r * PI << "\n" << "Ahora vamos a modificar PI (no se puede porque es constante y el compilador lanza un error ;) )\n";
	//PI = PI * 2;
}
