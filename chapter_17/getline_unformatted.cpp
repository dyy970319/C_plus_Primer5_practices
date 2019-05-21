#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ifstream file("test.txt");
	char *ch = new char[10];
	do{
		file.getline(ch,9,'\n');
		cout.write(ch,file.gcount());
	}while(file.gcount() != 0);
	
	delete ch;
}