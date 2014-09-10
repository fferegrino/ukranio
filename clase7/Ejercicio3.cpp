#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
char randomChar();
int findWord();
int N;
string toFind = "IPN";

#ifdef CSTRINGS
char * palabrota = NULL;
#else
string palabrota;
char palabrita [4];
#endif

int main(int argc, char ** argv)
{
	//srand(time(NULL));
	double x, y;
	if(argc != 2)
		cin >> N;
	else
		N = atoi(argv[1]);
	
	for(int i = 0; i < N; i++){
		#ifdef CSTRINGS
		palabrota = (char *) realloc(palabrota, sizeof(char) * 4 * i+1);
		palabrota[i * 4] = randomChar();
		palabrota[i * 4 + 1] = randomChar();
		palabrota[i * 4 + 2] = randomChar();
		palabrota[i * 4 + 3] = ' ';
		#else
		palabrita[0] = randomChar();
		palabrita[1] = randomChar();
		palabrita[2] = randomChar();
		palabrita[3] = ' ';
		palabrota.append(palabrita);
		#endif
	}
	#ifdef CSTRINGS
	palabrota[N * 4] = '\0';
	cout << "Ocurrencias de " << toFind << ": " << findWord() << endl;
	#else
	int ix = 0, cnt = 0; 
	ix = palabrota.find(toFind, 0);
	while(ix >= 0){
		cnt++;
		if(ix == -1) break;
		ix = palabrota.find(toFind, ix+1);
	}
	cout << "Ocurrencias de " << toFind << ": " << cnt << endl;
	#endif
}

char randomChar(){
	return ((char) abs(rand() % 26)) + 'A';
}

int findWord(){
	int count = 0;
	int l = 0; while(toFind[++l]);
	for(int i = 0; i < N * 4; i+=4){
		for(int j = 0; j < l && palabrota[i+j] == toFind[j]; j++){
			if(j == l-1) count++;
		}
	}
	return count;
}
