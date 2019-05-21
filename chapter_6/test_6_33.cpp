#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>
#include <cassert>

//#define NDEBUG

using namespace std;
using std::vector;

void print(auto beg,auto end){
	#ifndef NDEBUG
		cout<<*beg<<endl;
	#endif
	++beg;
	if(beg != end)
		print(beg,end);
}

int main()
{
	vector<int> vi(10);
	assert(vi.end()-vi.begin() < 5);
	print(vi.begin(),vi.end());
}
	
