#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>
#include <fstream>
#include <sstream>

using namespace std;
using std::vector;

int main()
{
	ifstream in("test.txt");
	vector<string> stringVec;
	string line;
	while(getline(in,line))
		stringVec.push_back(line);
	
	for(auto beg = stringVec.begin();beg != stringVec.end();++beg){
		istringstream strRead(*beg);
		string word;
		while(strRead>>word)
			cout<<word<<endl;
	}
}
	
