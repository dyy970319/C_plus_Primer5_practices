#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>
#include <fstream>

using namespace std;
using std::vector;

int main()
{
	vector<string> str;
	string line;
	string ifile = "test.txt";
	ifstream in(ifile);
	while(in>>line){
		str.push_back(line);
	}
	cout<<str[1]<<endl;
}
	
