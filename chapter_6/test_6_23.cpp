#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

void print(int i,const int j[2]){
	for(;i<2;++i){
		cout<<j[i]<<endl;
	}
}

void print2(const int *beg,const int *end){
	while(beg != end)
		cout<<*beg++<<endl;
}

void print3(const int ia[],size_t size){
	for(size_t i = 0;i != size;++i)
		cout<<ia[i]<<endl;
}

void print4(int (&arr)[2]){
	for(auto elem : arr)
		cout<<elem<<endl;
}

int main()
{
	int i = 0,j[2] = {0,1};
	print4(j);
}
