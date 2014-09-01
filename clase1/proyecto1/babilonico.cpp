#include <iostream>

int main(){
	int N;
	double n, r, t = 0;
	std::cout.setf(std::ios::fixed);
	std::cout.setf(std::ios::showpoint);
	std::cout.precision(4);
	std::cin >> N; N++;
	while(--N){
		std::cin >> n;
		t = 0;
		r = n;
		while (t != r){
			t = r;
			r = (n /r + r)/2;
			// std::cout  << "\t" << r << std::endl;
		}
		std::cout << "sqrt("<< n << ") = " << r << "\n";
	}
	
}
