#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> ivec;
	cout<<"ivec: size:"<<ivec.size()
		<<"capacity:"<<ivec.capacity()<<endl;
	for(vector<int>::size_type ix = 0;ix != 24;++ix){
		ivec.push_back(ix);
	cout<<"ivec: size:"<<ivec.size()
		<<"capacity:"<<ivec.capacity()<<endl;
	}
}
