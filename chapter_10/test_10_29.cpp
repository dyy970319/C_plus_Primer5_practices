#include <fstream>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	ifstream inFile("test.txt");
	istream_iterator<string> item_iter(inFile),eof;
	vector <string> vs;
	copy(item_iter,eof,inserter(vs,vs.begin()));
	cout<<vs[0]<<endl;
}