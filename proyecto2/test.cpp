#pragma GCC diagnostic ignored "-Wwrite-strings"
#include <dirent.h> 
#include <iostream> 
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <fcntl.h>	
#include <string>

using namespace std;
vector<string> files;
char buffer[1024];
int main()
{
	string asterisks = string("*************************************\n");
	string line = string("\n");
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir (".")) != NULL) 
	{
		/* print all the files and directories within directory */
		while ((ent = readdir (dir)) != NULL) 
		{
			files.push_back(string(ent->d_name));
		}
		closedir (dir);
	} 
	else 
	{
		return -1;
	}
	
	int bytes,b, origen, destino;
	sort(files.begin(), files.end());
	destino = open("_out.txt", O_WRONLY|O_TRUNC|O_CREAT, 0666);
	for(int i = 0; i < files.size();i++)
	{
		bytes  = 0;
		b = 0;
		origen = open(files[i].c_str(), O_RDONLY);
		if('_' != files[i][0] && '.' != files[i][0])
		{
			write(destino, files[i].c_str(), files[i].size());
			write(destino, line.c_str(), line.size());
			while((b = read(origen, buffer, 1024)) > 0)
			{
				bytes += b;
				write(destino, buffer, b);
			}
			write(destino, asterisks.c_str(), asterisks.size());
		}
		cout << files[i] << " " << bytes << endl;
		close(origen);
	}
	close(destino);
}
