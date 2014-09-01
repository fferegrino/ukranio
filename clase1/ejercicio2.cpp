#include <iostream>
using namespace std;
const double PI =  3.1415926;
int main()
{
	int i1 = 3, i2 = 4;
	double d1 = 4.0;
	cout << "La siguiente es conocida como division entera, esta solo deja la parte entera del resultado:\n";
	cout << i1 << " / " << i2 << " = " << i1 / i2 << "\n";
	cout << "La siguiente es conocida como division \"flotante\", esta si deja los decimales al resultado:\n";
	cout << i1 << " / " << d1 << " = " << i1 / d1 << "\n";
}
