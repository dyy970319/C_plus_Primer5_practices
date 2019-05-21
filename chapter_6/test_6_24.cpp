#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

void print(const int ia[10]){
	for(size_t i =0;i !=10;++i)
		cout<<ia[i]<<endl;
}

int main()
{
	int ia[10] = {0,0,0,0,0,0,0,0,0,0};
	print(ia);
}
