#include <fstream>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	istream_iterator<int> in_iter(cin),eof;
	vector<int> temp;
	ostream_iterator<int> out_iter(cout);
	while(in_iter != eof)
		temp.push_back(*in_iter++);
	sort(temp.begin(),temp.end());
	unique_copy(temp.cbegin(),temp.cend(),out_iter);
	/*for(auto beg = temp.begin(); beg != temp.end(); ++beg)
	{
		out_iter = *beg;
	}*/
	
}