#include <iostream>
const double gforce = 9.81;

int main(){
	int N;
	double tiempo;
	std::cin >> N; N++;
	while(--N){
		std::cin >> tiempo;
		std::cout << gforce * tiempo * tiempo << "\n";
	}
}
