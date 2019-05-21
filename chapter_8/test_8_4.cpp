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
	while(getline(in,line)){
		str.push_back(line);
	}
	cout<<str[0]<<endl;
}
	
