#include <iostream>
const int hsecs = 3600;
const int msecs = 60;
void convierte(int secs, int& hours, int& minutes, int& seconds);

int main(){
	int N, secs, h, m , s;
	std::cin >> N; N++;
	while(--N){
		std::cin >> secs;
		convierte(secs, h, m, s);
		std::cout <<  h << " horas, " << m << " minutos y " << s << " segundos.\n";
	}
}

void convierte(int secs, int& hours, int& minutes, int& seconds){
	hours = secs / hsecs;
	minutes = secs % hsecs;
	seconds = minutes % msecs;
	minutes = minutes / msecs;
}
